*This project has been created as part of the 42 curriculum by  &lt;hukhaw&gt;, &lt;smushrof&gt;.*

<div align="center">

# push_swap

### Because Swap_push doesn't feel as natural

Sort a stack of integers with only two stacks and a handful of moves, 
using the fewest operations possible.

![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-CC6633?style=for-the-badge&logo=gnu&logoColor=white)

</div>

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
  - [Compilation](#compilation)
  - [Usage](#usage)
  - [Error handling](#error-handling)
  - [Bonus: checker](#bonus-checker)
- [Algorithms](#algorithms)
  - [Common preprocessing: ranks](#common-preprocessing-ranks)
  - [Disorder metric](#disorder-metric)
  - [Strategy 1: Simple, O(n²)](#strategy-1-simple-on)
  - [Strategy 2: Medium, O(n√n)](#strategy-2-medium-onn)
  - [Strategy 3: Complex, O(n log n)](#strategy-3-complex-on-log-n)
  - [Strategy 4: Adaptive](#strategy-4-adaptive)
- [Benchmarks](#benchmarks)
- [Project structure](#project-structure)
- [Contributions](#contributions)
- [Resources](#resources)

## Description

`push_swap` sorts a stack of integers using only two stacks (`a` and `b`) and a
restricted instruction set, and prints the **shortest list of instructions it
can find**. The goal of the project is to experience algorithmic complexity
concretely: the same input can produce very different operation counts
depending on the algorithm and on how disordered the input already is.

**Instruction set**

| Instruction | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both (top becomes bottom) |
| `rra` / `rrb` / `rrr` | reverse rotate `a` / `b` / both (bottom becomes top) |

**Overview of the program**

- Four strategies are embedded in the same binary: **Simple** `O(n²)`,
  **Medium** `O(n√n)`, **Complex** `O(n log n)` and **Adaptive**.
- The **disorder** of the input is measured before any move, and the Adaptive
  strategy uses it to choose one of the three others.
- An optional `--bench` mode prints statistics to `stderr`.
- Bonus: a `checker` program that executes an instruction list and answers
  `OK` / `KO`.

## Instructions

### Compilation

The project needs the `libft` folder (sources + Makefile) at the root of the
repository. Everything is compiled with `cc -Wall -Wextra -Werror`.

```
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

### Usage

```
./push_swap [strategy] [--bench] <integers...>
```

| Flag | Meaning |
|---|---|
| `--simple` | force the `O(n²)` strategy |
| `--medium` | force the `O(n√n)` strategy |
| `--complex` | force the `O(n log n)` strategy |
| `--adaptive` | choose the strategy from the disorder (**default**) |
| `--bench` | print benchmark information to `stderr` |

Flags can be placed anywhere among the arguments. If several strategy flags
are given, the last one wins. Numbers can be given as separate arguments or
inside one quoted string (`./push_swap "3 2 1"`).

The first number is the top of stack `a`. The program prints one instruction
per line on `stdout`.

**Examples**

```
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK
$> ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Error handling

| Input | Result |
|---|---|
| no argument at all | prints nothing, returns the prompt |
| not an integer, out of `int` range, duplicate, empty string | `Error\n` on `stderr` |
| already sorted | prints nothing |

**Design decision:** when arguments are given but contain only flags and no
number (e.g. `./push_swap --simple`), there is nothing to sort, so we treat it
as invalid input and print `Error`. The subject only defines the "no
parameters" case (`argc == 1`), and a flag is a parameter, so this case is
handled as an error rather than silently ignored.

### Bonus: `checker`

```
./checker <integers...>
```

Reads instructions from `stdin` (one per line, read with `get_next_line`),
executes them on stack `a`, then prints `OK` if `a` is sorted and `b` is
empty, `KO` otherwise. An invalid number, duplicate, or unknown/incorrectly
formatted instruction prints `Error` on `stderr`. With no argument it prints
nothing.

## Algorithms

### Common preprocessing: ranks

Before sorting, every value is replaced by its **rank** (its index in the
sorted list, `0 … n-1`). Ranks are computed by copying the values into an
array, sorting it with quicksort and finding each value by binary search. All
three strategies then work on ranks, which means every value is a distinct
integer in a contiguous range. This costs no push_swap operation.

Inputs that are already sorted print nothing, and inputs of 2 or 3 elements
are solved directly (at most 2 instructions) by a dedicated routine.

### Disorder metric

```
disorder = (number of pairs (i, j), i < j, with a[i] > a[j]) / (n·(n-1)/2)
```

It is `0` for a sorted stack and `1` for a reversed one. It is computed once,
before any instruction is executed. (Computing it is `O(n²)` in CPU time, but
it generates no push_swap instruction, and the complexity classes below are
measured in generated instructions, as required by the subject.)

### Strategy 1: Simple, `O(n²)`: greedy cheapest insertion

1. Repeatedly look at **every** node of `a` and compute the cost of pushing it
   to `b`:
   - the rotations needed to bring that node to the top of `a`, and
   - the rotations needed on `b` so that the node lands at its correct place.
   The target place in `b` is just below the largest rank smaller than the
   node; if none exists, the node goes next to the maximum of `b`.
2. When both stacks rotate in the same direction, the rotations are shared
   with `rr` / `rrr`, so only the larger of the two counts. Each stack always
   takes the shortest direction (`r*` or `rr*`).
3. Execute the cheapest move, then `pb`. This keeps `b` sorted in descending
   circular order.
4. When `a` is empty, rotate the maximum of `b` to the top and `pa` everything
   back.

**Why we chose it:** it is easy to reason about and defend, it is naturally
`O(n²)`, and the greedy cost model uses `rr` / `rrr` to save instructions.

**Complexity (instructions).** There are `n` pushes to `b`. For each one, the
rotations on `a` are at most `n/2` and the rotations on `b` at most `n/2`, so
each iteration costs `O(n)` instructions. The final phase costs at most `n/2`
rotations plus `n` `pa`. Total: `O(n) · O(n) + O(n) = O(n²)` instructions.
**Space:** `O(n)` for the two stacks, plus a temporary `O(n)` array while
computing ranks; no other extra memory.

*Note:* the selection of the cheapest node is done by scanning, which costs
more CPU time than `O(n²)`, but it is not counted in the push_swap model.

### Strategy 2: Medium, `O(n√n)`: sliding-window chunks

1. Chunk size `c = floor(√n) · 8 / 5` (about `1.6·√n`).
2. **Push phase.** Let `k` be the number of nodes already pushed. At each step,
   only nodes with `rank < k + c` are eligible. The eligible node **closest to
   the top or to the bottom** of `a` is brought to the top and pushed to `b`.
   If the pushed node has a small rank (`rank < k`), `b` is rotated afterwards
   so it sinks to the bottom of `b`; this `rb` is delayed and merged with the
   next `ra` into an `rr` whenever possible.
3. **Pull-back phase.** Repeatedly bring the largest rank of `b` to the top
   (shortest direction) and `pa` it. If the second largest is closer to the
   top, it is pulled first, then the largest, then `sa` fixes the order.

The pull-back phase only depends on ranks, so it always yields a sorted `a`
regardless of how the push phase behaved; the window heuristic only affects
the number of instructions.

**Why we chose it:** it is a well-known chunk method whose window keeps `b`
roughly ordered, so that the pull-back phase stays cheap.

**Complexity (instructions).** At every step of the push phase exactly
`min(c, remaining)` eligible nodes remain in `a`. For a random arrangement the
closest eligible node is on average `O(n / c) = O(√n)` positions away, so the
`n` pushes cost `O(n√n)`. The window also keeps each element within about
`c = O(√n)` positions of its final slot in `b`, so each of the `n` pulls costs
`O(√n)` rotations. Total: `O(n√n)`. This bound holds for the average case
(random input); an adversarial arrangement can push it towards `O(n²)`.
**Space:** `O(n)` for the stacks and the rank array.

### Strategy 3: Complex, `O(n log n)`: quicksort on two stacks

Recursive partitioning with two mutually recursive routines
(`quick_sort_a` and `quick_sort_b`), working on a segment of a known size at
the top of a stack:

1. `pivot = (min rank + max rank) / 2` of the segment.
2. **Segment on `a`:** for each element, if `rank >= pivot` it is rotated to
   the bottom of `a` (`ra`), otherwise it is pushed to `b` (`pb`). The
   rotations are then undone with the same number of `rra`, unless the segment
   was the whole stack (in which case the rotation is a no-op cycle).
   Then sort the elements kept in `a` and afterwards the ones pushed to `b`.
3. **Segment on `b`:** symmetric: `rank >= pivot` goes back to `a` (`pa`), the
   rest is rotated (`rb`) and restored with `rrb`.
4. Base cases: size 1 (nothing / one `pa`) and size 2 (a single `sa` / `sb`).

Because of the last-in-first-out order, the recursion always finds the
elements of its own segment on top of the stack, so segments never mix.

**Why we chose it:** quicksort is a natural `O(n log n)` fit for two stacks,
and because we sort ranks, the pivot is exactly the middle of the range.

**Complexity (instructions).** One partition of a segment of size `s` costs at
most `s` operations for the loop plus at most `s` for the restoration:
`O(s)`. Ranks form a permutation of `0 … n-1`, so every segment is always a
contiguous range of ranks and `(min + max) / 2` splits that range into two
halves. The recursion depth is therefore `⌈log₂ n⌉` and each level handles
`n` elements in total: `O(n log n)` instructions in the worst case.
**Space:** recursion depth `O(log n)` (each frame holds two integers), plus
`O(n)` for the stacks and rank array.

### Strategy 4: Adaptive

The disorder is measured first, then:

| Disorder | Strategy used | Class |
|---|---|---|
| `< 0.2` | Simple | `O(n²)` |
| `0.2 ≤ d < 0.5` | Medium | `O(n√n)` |
| `≥ 0.5` | Complex | `O(n log n)` |

**Rationale for the thresholds.** The values `0.2` and `0.5` come from the
subject; we keep them and justify them as follows. A low disorder means few
inversions, so only a small part of the input is misplaced and even a
quadratic method spends few instructions in practice. As disorder grows, the
number of misplaced elements grows and the quadratic method's cost rises
sharply, so a middle regime with `O(n√n)` is used. Above `0.5` (more than half
of all pairs inverted, i.e. closer to reversed than to sorted) the instruction
count of quadratic methods explodes and only an `O(n log n)` method is
reasonable.

`--bench` reports the class actually selected, for example
`Adaptive / O(n√n)`.

**Complexity.** The adaptive strategy runs exactly one of the three above, so
its bounds per regime are those of the selected strategy: `O(n²)`,
`O(n√n)` or `O(n log n)` instructions, with `O(n)` space (plus `O(log n)`
recursion in the complex regime).

## Project structure

| Area | Files |
|---|---|
| entry point | `ft_push_swap.c` |
| parsing / validation | `ps_parse_and_validation.c`, `ps_utils_a.c`, `ps_utils_b.c` |
| instructions | `ps_swap.c`, `ps_push.c`, `ps_rotate.c`, `ps_reverse_rotate.c` |
| ranking / helpers | `ps_ranking.c`, `ps_is_sorted.c`, `ps_sort_small.c` |
| disorder / bench | `ps_compute_disorder_and_symbol.c`, `ps_bench.c` |
| simple | `ps_simple.c`, `ps_simple_cost.c`, `ps_simple_exec.c` |
| medium | `ps_medium_sort.c`, `ps_medium_push.c`, `ps_medium_pull.c`, `ps_medium_utils.c` |
| complex | `ps_complex_quick_sort.c`, `ps_complex_quick_sort_utils.c` |
| bonus checker | `bonus/*_bonus.c`, `bonus/ft_checker_bonus.h` |

## Contributions

| Learner | Contribution |
|---|---|
| hukhaw | all of the project |
| smushrof | `instructions` |


## Resources

**References**

- [Hello Algo](https://www.hello-algo.com/en/)
- Robert Sedgewick — *Algorithms in C*

**Use of AI**

An AI assistant was used for:

- helping in understand the logic behind: insertion sort, greedy insertion,
  chunk-based sorting, sliding-window chunk sort, radix sort (LSD and MSD),
  quicksort, the concept of mutual recursion, and Big-O notation;
- reviewing our code for logic errors and edge cases (parsing, integer
  overflow, empty arguments, memory leaks and NULL checks);
- checking the Makefile (relinking, header dependencies, `.PHONY`);
- drafting this README.
