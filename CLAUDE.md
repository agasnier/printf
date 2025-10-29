# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a 42 School project implementing a custom printf function (`ft_printf`) that mimics the behavior of the standard C library's printf function. The implementation uses variadic functions (va_list, va_start, va_arg) to handle variable arguments.

## Build and Test Commands

```bash
# Build and run (compiles with all flags and executes immediately)
make

# Manual compilation
cc -Werror -Wextra -Wall ft_printf.c libft/libft.a

# Run the compiled program
./a.out
```

The Makefile automatically clears the terminal, compiles with strict flags (`-Werror -Wextra -Wall`), and runs the executable.

## Architecture

### Core Structure

- **ft_printf.c**: Main implementation file containing:
  - `ft_printf()`: Main variadic function that parses format string and dispatches to format handlers
  - Format handler functions: `ft_char()`, `ft_str()`, `ft_integer()`, `ft_pourcent()`
  - `main()`: Test suite that compares ft_printf output with standard printf

- **libft/**: Pre-built static library containing utility functions
  - `libft.a`: Compiled static library
  - `libft.h`: Header with string manipulation, memory, and conversion functions
  - Key dependencies used by ft_printf: `ft_itoa()`, `ft_putstr_fd()`, `ft_strlen()`

### Current Implementation Status

**Implemented format specifiers:**
- `%c`: Single character (via `ft_char`)
- `%s`: String (via `ft_str`)
- `%d`: Decimal integer (via `ft_integer`)
- `%%`: Literal percent sign (via `ft_pourcent`)

**Not yet implemented:**
- `%p`: Pointer in hexadecimal
- `%i`: Integer in base 10
- `%u`: Unsigned decimal
- `%x`: Hexadecimal lowercase
- `%X`: Hexadecimal uppercase

### Function Flow

The `ft_printf` function iterates through the format string character by character. When it encounters a `%`, it checks the next character to determine the format specifier and calls the appropriate handler function. Each handler:
1. Processes the variadic argument via `va_arg()`
2. Outputs to stdout (fd 1)
3. Returns the number of characters printed

The function tracks total characters printed in `len_print` and returns this count.

## Important Notes

- All compilation must use `-Werror -Wextra -Wall` flags (42 standard)
- The main function contains test comparisons against standard printf to verify correctness
- Memory management: `ft_integer` allocates memory via `ft_itoa` and must free it
- The libft library is pre-compiled; source files are not in this directory
