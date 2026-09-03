*This project has been created as part of the 42 curriculum by &lt;hukhaw&gt;.*

<div align="center">

# 📚 libft

### Your very first own C library

Reimplementing the essential libc functions, plus additional string, memory, and linked-list utilities. Learn to built `ft_` from scratch.

[![42](https://img.shields.io/badge/42-libft-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
![C](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen?style=for-the-badge)
![Makefile](https://img.shields.io/badge/build-Makefile-orange?style=for-the-badge)

</div>

---

## 📑 Table of Contents

- [1. Description](#1-description)
- [2. Library Overview](#2-library-overview)
  - [2.1 Part 1 — Libc Functions](#21-part-1--libc-functions)
  - [2.2 Part 2 — Additional Functions](#22-part-2--additional-functions)
  - [2.3 Part 3 — Linked List](#23-part-3--linked-list)
- [3. Instructions](#3-instructions)
  - [3.1 Clone](#31-clone)
  - [3.2 Compile](#32-compile)
  - [3.3 Use in Another Project](#33-use-in-another-project)
  - [3.4 Debugging with Sanitizers](#34-debugging-with-sanitizers)
- [4. Resources](#4-resources)

---

## 1. Description

**libft** is the first project of the 42 core curriculum. The goal is to build a personal
C static library, `libft.a`, that re-implements a set of standard `libc` functions and adds
custom utility functions for string manipulation, memory management, and also linked
lists.

The objective of this project is to understand *how* these foundational functions actually work under the hood like
memory allocation, pointer arithmetic, buffer handling, and edge cases. This `libft.a` becomes the base toolkit
reused throughout the rest of the 42 curriculum.

---

## 2. Library Overview

### 2.1 Part 1 — Libc Functions

Custom re-implementations of standard `<ctype.h>` and `<string.h>` functions, prefixed
with `ft_`, matching the original prototypes and behavior exactly,
without relying on any external function calls.

| Category | Functions |
|---|---|
| Character classification | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| String length / conversion | `ft_strlen`, `ft_atoi`, `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| String copy / concat | `ft_strlcpy`, `ft_strlcat` |
| String search | `ft_strchr`, `ft_strrchr`, `ft_strnstr` |
| String compare | `ft_strncmp` |
| Allocation-based | `ft_calloc`, `ft_strdup` |

> **PS:** `ft_calloc` and `ft_strdup` are allowed to rely on
> `malloc()` internally, since there is no way to allocate heap memory otherwise.
>
> Also note that `ft_calloc`'s behavior intentionally differs from what you might see on
> some systems: if `nmemb` or `size` is `0`, it still returns a unique, valid pointer that
> can be safely passed to `free()`, instead of returning `NULL`.

### 2.2 Part 2 — Additional Functions

Functions that don't exist in the standard `libc`, or exist in a different form.

| Function | Purpose |
|---|---|
| `ft_substr` | Extract a substring from a given string |
| `ft_strjoin` | Concatenate two strings into a newly allocated one |
| `ft_strtrim` | Trim leading/trailing characters from a set |
| `ft_split` | Split a string into an array of strings by a delimiter |
| `ft_itoa` | Convert an integer to a newly allocated string |
| `ft_strmapi` | Apply a function to each char of a string, building a new string |
| `ft_striteri` | Apply a function to each char of a string, in place |
| `ft_putchar_fd` | Output a character to a given file descriptor |
| `ft_putstr_fd` | Output a string to a given file descriptor |
| `ft_putendl_fd` | Output a string + newline to a given file descriptor |
| `ft_putnbr_fd` | Output an integer to a given file descriptor |

### 2.3 Part 3 — Linked List

A linked list toolkit built around the `t_list` structure:

```c
typedef struct s_list
{
	void           *content;
	struct s_list  *next;
}                t_list;
```

| Function | Purpose |
|---|---|
| `ft_lstnew` | Create a new node |
| `ft_lstadd_front` | Add a node at the beginning of the list |
| `ft_lstadd_back` | Add a node at the end of the list |
| `ft_lstsize` | Count the number of nodes in a list |
| `ft_lstlast` | Return the last node of a list |
| `ft_lstdelone` | Free a single node and its content |
| `ft_lstclear` | Free an entire list and its content |
| `ft_lstiter` | Apply a function to each node's content |
| `ft_lstmap` | Apply a function to each node's content, building a new list |

---

## 3. Instructions

### 3.1 Clone

```bash
git clone https://github.com/gabbycommit/42_libft.git
cd 42_libft
```

### 3.2 Compile

```bash
make        # compiles ft_*.c into libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

The library is built with `ar` (not `libtool`), using `-Wall -Wextra -Werror`, and the
resulting `libft.a` is created at the root of the repository.

### 3.3 Use in Another Project
 
Once `libft.a` is built, there are two common ways to link it against another program.
 
**Option A: pass the `.a` file directly**
 
```bash
cc -Wall -Wextra -Werror your_file.c libft.a -o your_program
```
 
The linker treats `libft.a` like any other object file you hand it directly. No lookup
involved. Simple and explicit, as long as the path to `libft.a` is correct.
 
**Option B: use `-L` / `-l` (standard library-linking convention)**
 
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```
 
- `-L<dir>` tells the linker which directory to search for libraries in (`-L.` means
  "look in the current directory")
- `-lft` tells it to search that directory (and the system's default paths) for a file
  named `libft.a` (static) or `libft.so` (dynamic)
This is the idiomatic way libraries are linked in C. It's how system libraries like
`-lm` or `-lpthread` are linked too, and it scales better once a project links several
libraries or supports both static and dynamic builds without changing the compile
command.
 
Either way, make sure `libft.h` is included and accessible via your include path (`-I`
flag if it lives elsewhere).
 
### 3.4 Debugging with Sanitizers
 
The `Makefile` includes an `fsanitize` rule that rebuilds `libft.a` with
`-fsanitize=address -fsanitize=undefined -g3`, so memory errors, invalid frees, and
undefined behavior surface immediately instead of failing silently:
 
```bash
make fsanitize
```
 
Then link your own test file against this sanitized `libft.a` the same way as usual:
 
```bash
cc -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined your_test.c -L. -lft -o test
./test
```
 
---


## 4. Resources

**Documentation & references:**

- [`man` command in terminal](https://man7.org/linux/man-pages/man3) — the primary source for every function's exact prototype and behavior (`man <function>`)
- [Linux man-pages, Section 3 (Library Functions)](https://man7.org/linux/man-pages/man3)
- [POSIX.1-2024 Specification (The Open Group)](https://pubs.opengroup.org/onlinepubs/9799919799/)
- [GCC command in Linux, with examples — GeeksforGeeks](https://www.geeksforgeeks.org/linux-unix/gcc-command-in-linux-with-examples/)
- [Static Library vs Dynamic Library — Medium](https://medium.com/@abhishekjainindore24/static-library-vs-dynamic-library-understanding-the-differences-26e47cac93b6)
- [GitHub Basic Writing and Formatting Syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- [Shields.io](https://shields.io) — used to generate the badges in this README
