*This project has been created as part of the 42 curriculum by hukhaw, smushrof.*

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
  - [Strategy 1: Simple](#strategy-1-simple)
  - [Strategy 2: Medium](#strategy-2-medium)
  - [Strategy 3: Complex](#strategy-3-complex)
  - [Strategy 4: Adaptive](#strategy-4-adaptive)
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

An instruction on a stack that has too few elements does nothing.

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

he project needs the `libft` folder (sources + Makefile) at the root of the
repository; the Makefile builds it automatically. Everything is compiled with
`cc -Wall -Wextra -Werror`.

```
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files (also in libft)
make fclean   # removes object files and binaries (also libft.a)
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

Flags can be placed anywhere among the arguments and must be written exactly
as above. If several strategy flags are given, the last one wins. Numbers can
be given as separate arguments or inside one quoted string
(`./push_swap "3 2 1"`); inside a string, numbers are separated by spaces.

The first number is the top of stack `a`. The program prints one instruction
per line on `stdout`.

**Examples**

```
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK
$> ./push_swap --bench --complex $ARG 2> bench.txt | ./checker $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 14
[bench] sa: 1 sb: 0 ss: 0 pa: 4 pb: 4
[bench] ra: 2 rb: 2 rr: 0 rra: 1 rrb: 0 rrr: 0
```

In Adaptive mode, the strategy line shows the class that was actually
selected, for example `Adaptive / O(n√n)`.

### Error handling

| Input | Result |
|---|---|
| no argument at all | prints nothing, returns the prompt |
| not an integer (`1a`, `1.5`, `-`, `1\t2`) | `Error\n` on `stderr` |
| out of `int` range (`2147483648`) | `Error\n` on `stderr` |
| duplicate (`1 1`, also `0 -0`) | `Error\n` on `stderr` |
| empty or blank string (`""`, `"  "`) | `Error\n` on `stderr` |
| only flags, no number (`--simple`) | `Error\n` on `stderr` |
| already sorted, or a single number | prints nothing |

A number is an optional `+` / `-` followed by digits only. Its value is read
as a `long` (clamped on overflow), so any value outside the `int` range is
rejected.

**Design decision:** when arguments are given but contain only flags and no
number (e.g. `./push_swap --simple`), there is nothing to sort, so we treat it
as invalid input and print `Error`. The subject only defines the "no
parameters" case (`argc == 1`), and a flag is a parameter, so this case is
handled as an error rather than silently ignored.

### Bonus: `checker`

```
./checker <integers...>
```

- Numbers are parsed with the same rules as `push_swap` (flags are not
  accepted: `--bench` is an invalid number). With no argument it prints
  nothing.
- Instructions are read from `stdin` with `get_next_line`, one per line, until
  end of input. Each line must be exactly one instruction followed by `\n`
  (so `sa` without a final newline, an empty line or `sa ` are errors).
- After the last instruction, it prints `OK` if `a` is sorted and `b` is
  empty, `KO` otherwise.
- An invalid number, a duplicate, or an unknown / badly formatted instruction
  prints `Error` on `stderr`.

## Algorithms

### Common preprocessing: ranks

Each strategy starts by replacing every value by its **rank** (its index in
the sorted list, `0 … n-1`). The values are copied into an array, the array is
sorted with quicksort, and each value is found in it by binary search. From
then on the strategies only compare ranks, so every value is a distinct
integer in a contiguous range. This costs no push_swap instruction.

Inputs that are already sorted print nothing, and inputs of 2 or 3 elements
are solved with at most 2 instructions.

### Disorder metric

```
disorder = (number of pairs (i, j), i < j, with a[i] > a[j]) / (n·(n-1)/2)
```

It is `0` for a sorted stack and `1` for a reversed one. It is computed once,
on the original values, before any instruction is executed. (Computing it is
`O(n²)` in CPU time, but it generates no push_swap instruction, and the
complexity classes below are measured in generated instructions, as required
by the subject.)

### Strategy 1: Simple

**Class:** `O(n²)` instructions. **Idea:** greedy cheapest insertion back
into `a`.

1. **Pre-push.** Push every element except 3 to `b`. After each `pb`, if the
   pushed element belongs to the smaller half (`rank < n/2`), `b` is rotated
   (`rb`) so it goes to the bottom. `b` ends up roughly split: big ranks on
   top, small ranks at the bottom.
2. **Sort the 3 left in `a`** with at most 2 instructions. From now on, `a` is
   always sorted *circularly* (sorted, but possibly rotated).
3. **Insertion loop.** While `b` is not empty, look at **every** element of
   `b` and compute the cost of inserting it into `a`:
   - its **target** in `a` is the element with the smallest rank greater than
     its own; if there is none, it is the minimum of `a`. Putting the element
     directly on top of its target keeps `a` circularly sorted;
   - the cost is the number of rotations to bring the element to the top of
     `b` plus the rotations to bring its target to the top of `a`. All four
     direction combinations (`ra`+`rb`, `rra`+`rrb`, `ra`+`rrb`, `rra`+`rb`)
     are tried. When both stacks turn in the same direction, the moves are
     shared with `rr` / `rrr`, so only the larger of the two counts.

   The cheapest element is brought to the top (shared moves first, then the
   remaining ones), then `pa`.
4. **Final rotation.** Rotate the minimum of `a` to the top in the shortest
   direction.

**Why we chose it:** it is easy to reason about and defend, and the cost
model takes full advantage of `rr` / `rrr`. The pre-push by halves gives the
insertion loop cheaper choices.

**Complexity (instructions).** The pre-push costs at most 2 instructions per
element: `O(n)`. There are then `n - 3` insertions. Each one costs at most the
rotations of `a` plus those of `b`, which is at most `n`, plus one `pa`: `O(n)`
per insertion. The final rotation costs at most `n/2`. Total:
`O(n) + O(n) · O(n) + O(n) = O(n²)` instructions.
**Space:** `O(n)` for the two stacks, plus a temporary `O(n)` array while
computing ranks.

*Note:* finding the cheapest element (scanning `b` and searching each target
in `a`) costs more CPU time than `O(n²)`, but it generates no instruction.

### Strategy 2: Medium

**Class:** `O(n√n)` instructions. **Idea:** sliding-window chunks.

1. Chunk size `c = floor(√n) · 8 / 5` (about `1.6·√n`).
2. **Push phase.** Let `k` be the number of elements already pushed. At each
   step, only elements with `rank < k + c` are eligible. The eligible element
   **closest to the top or to the bottom** of `a` is brought to the top and
   pushed to `b`. If the pushed element has a small rank (`rank < k`), `b` is
   rotated afterwards so it sinks to the bottom of `b`; this `rb` is delayed
   and merged with the next `ra` into an `rr` whenever possible.
3. **Pull-back phase.** Repeatedly bring the largest rank of `b` to the top
   (shortest direction) and `pa` it. If the second largest is closer to the
   top, it is pulled first, then the largest, then `sa` fixes the order.

The pull-back phase only depends on ranks, so it always yields a sorted `a`
regardless of how the push phase behaved; the window heuristic only affects
the number of instructions.

**Why we chose it:** it is a well-known chunk method whose window keeps `b`
roughly ordered, so that the pull-back phase stays cheap.

**Complexity (instructions).** At every step of the push phase exactly
`min(c, remaining)` eligible elements remain in `a`. For a random arrangement
the closest eligible element is on average `O(n / c) = O(√n)` positions away,
so the `n` pushes cost `O(n√n)`. The window also keeps each element within
about `c = O(√n)` positions of its final slot in `b`, so each of the `n` pulls
costs `O(√n)` rotations. Total: `O(n√n)`. This bound holds for the average
case (random input); an adversarial arrangement can push it towards `O(n²)`.
**Space:** `O(n)` for the stacks and the rank array.

### Strategy 3: Complex

**Class:** `O(n log n)` instructions. **Idea:** three-way quicksort on four
locations.

**The four locations.** The two stacks are treated as four places where a
group of elements (a *chunk*) can sit: `TOP_A`, `BOTTOM_A`, `TOP_B` and
`BOTTOM_B`. One element can be moved between any two locations with at most 3
instructions: an `rra` / `rrb` to take it from a bottom, a `pa` / `pb` if it
changes stack, and an `ra` / `rb` to drop it at a bottom.

A chunk is described by its location, its size and its lowest rank `lo`.
Because we work on ranks, a chunk always contains exactly the ranks
`lo … lo + size - 1`, so its minimum and maximum are known without looking at
the stack.

**The sorted block.** The finished part of the result is a contiguous block
in `a`, and it grows upward: every element is finished by being placed on
`TOP_A`, directly above the block. For this to work, the chunk containing the
largest ranks must always be finished first.

**Algorithm** (recursive, starting with the whole of `a` as one chunk at
`TOP_A`):

1. **Fix the location.** If the chunk is at `BOTTOM_A` (or `BOTTOM_B`) but is
   the entire stack, reading it from the top is equivalent. It is relabelled
   `TOP_A` (or `TOP_B`), which saves one `rra` / `rrb` per element.
2. **Easy moves.** While the next element available at the chunk's location
   is the chunk's maximum, it is exactly the next value the sorted block
   needs. It is moved straight to `TOP_A` and the chunk shrinks by one.
3. **Base case (size ≤ 3).** The chunk is moved to `TOP_A` and sorted there:
   - 2 elements: at most one `sa`;
   - 3 elements that are all of `a`: at most one rotation and one `sa`;
   - 3 elements on top of the sorted block: only `sa` and the sequence
     `ra sa rra`, so the block underneath is never touched.
4. **Split into three.** Otherwise the chunk is split by rank into a *max*
   part (top third), a *mid* part (middle third) and a *min* part (the rest).
   Each element is read once from the chunk's location and sent to the
   location of its part. The three destinations are always the three
   locations the chunk is not in:

   | Chunk at | max goes to | mid goes to | min goes to |
   |---|---|---|---|
   | `TOP_A` | `BOTTOM_A` | `TOP_B` | `BOTTOM_B` |
   | `BOTTOM_A` | `TOP_A` | `TOP_B` | `BOTTOM_B` |
   | `TOP_B` | `TOP_A` | `BOTTOM_A` | `BOTTOM_B` |
   | `BOTTOM_B` | `TOP_A` | `BOTTOM_A` | `TOP_B` |

   The max part always stays in `a` or goes to it, because it is the next one
   to be finished. For a chunk in `a` with fewer than 15 elements, the chunk
   is only split in two (max and mid). This avoids sending a few elements to
   the bottom of `b` and bringing them back.
5. **Recurse** on max, then mid, then min.

**Why segments never mix.** Each location behaves like a pile: new chunks are
placed on its outer end, and the chunk being processed is always the most
recently placed one, because the largest part is always handled first and
fully finished before its siblings. So the next element read from a location
always belongs to the current chunk.

**Why we chose it:** a classic two-stack quicksort splits in two and then
spends extra `rra` / `rrb` to undo its rotations. Using all four locations
means a split never needs to be undone, and splitting in three instead of two
gives fewer recursion levels.

**Complexity (instructions).** A split of a chunk of size `s` moves each
element once, at most 3 instructions per move, so it costs `O(s)`. Since
chunks are split by rank value, not by position, the parts always have sizes
close to `s/3` whatever the input order. The recursion depth is therefore
about `log₃ n`. The two-way split for small chunks only applies below 15
elements, so it adds only a constant number of levels. Each level moves `n`
elements in total, and the base cases cost `O(1)` each. Total:
`O(n log n)` instructions, **in the worst case as well**, because the pivot
values come from ranks and never depend on the input order.
**Space:** `O(n)` for the stacks and rank array, plus the recursion depth
`O(log n)`, where each frame holds three chunk descriptors.

*Note:* reading the bottom of a stack walks the list, which costs CPU time,
but it generates no push_swap instruction.

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

**Complexity.** The adaptive strategy runs exactly one of the three above, so
its bounds per regime are those of the selected strategy: `O(n²)`,
`O(n√n)` or `O(n log n)` instructions, with `O(n)` space (plus `O(log n)`
recursion in the complex regime).

## Project structure

| Area | Files |
|---|---|
| entry point | `ft_push_swap.c`, `ft_push_swap.h` |
| parsing / validation | `ps_parse_and_validation.c`, `ps_utils_a.c`, `ps_utils_b.c` |
| instructions | `ps_swap.c`, `ps_push.c`, `ps_rotate.c`, `ps_reverse_rotate.c` |
| ranking / small sort | `ps_ranking.c`, `ps_sort_small.c` |
| disorder / bench | `ps_compute_disorder_and_symbol.c`, `ps_bench.c` |
| simple | `ps_simple_sort.c`, `ps_simple_cost.c`, `ps_simple_exec.c` |
| medium | `ps_medium_sort.c`, `ps_medium_push.c`, `ps_medium_pull.c`, `ps_medium_utils.c` |
| complex | `ps_complex_quick_sort.c`, `ps_complex_quick_sort_utils.c`, `ps_complex_split.c`, `ps_complex_sort_small.c` |
| bonus checker | `ft_checker_bonus.c`, `ft_checker_bonus.h`, `ps_exec_ops_bonus.c`, `get_next_line_bonus.c`, `ps_parse_and_validation_bonus.c`, `ps_*_bonus.c` (instructions and utils) |

## Contributions

| Learner | Contribution |
|---|---|
| hukhaw | `parsing / validation`, `disorder / bench`, `simple`, `medium`, `bonus` |
| smushrof | `instructions`, `entry point`, `complex`, `ranking / small sort` |

## Resources

**References**

- [Hello Algo](https://www.hello-algo.com/en/)
- Robert Sedgewick — *Algorithms in C*

**Use of AI**

An AI assistant was used for:

- helping in understand the logic behind: insertion sort, greedy insertion,
  chunk-based sorting, sliding-window chunk sort, radix sort (LSD and MSD),
  quicksort, two-way quicksort, three-way quicksort, the concept of mutual recursion, and Big-O notation;
- reviewing our code for logic errors and edge cases (parsing, integer
  overflow, empty arguments, memory leaks and NULL checks);
- checking the Makefile (relinking, header dependencies, `.PHONY`);
- drafting this README.
