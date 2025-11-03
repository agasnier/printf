# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a `ft_printf` implementation - a custom recreation of the C standard library's `printf` function, part of the 42 school curriculum. The project produces a static library `libftprintf.a` that can be linked with other programs.

## Build Commands

```bash
# Build the library
make

# Clean object files
make clean

# Clean everything (objects + library)
make fclean

# Rebuild from scratch
make re

# Run tests (requires main.c and ft_printf.a)
make test
```

**Important**: The Makefile currently has an issue - it references libft source files that were deleted from git but still exist in the working directory. The libft files are present but marked as deleted in git status.

## Architecture

### Core Flow
The printf implementation follows a multi-stage pipeline:

1. **Entry Point** (`ft_printf.c`):
   - `ft_printf()` - Main function, handles variadic arguments
   - `ft_printf_helper()` - Parses format string, delegates to orchestrator

2. **Format String Parsing** (`ft_orchestror.c`):
   - `ft_operator()` - Orchestrates the entire conversion process for each format specifier
   - `ft_create_str()` - Dispatches to appropriate formatter based on specifier
   - `ft_apply_struct()` - Applies flags in correct precedence order

3. **Struct Management** (`ft_struct.c`):
   - `ft_init_struct()` - Initializes format data structure
   - `ft_pars_flags()` - Parses flags: `#`, `-`, `0`, `+`, ` `
   - `ft_pars_width()` - Parses field width
   - `ft_pars_preci()` - Parses precision (`.`)
   - `ft_pars_speci()` - Identifies conversion specifier

4. **Format Conversions**:
   - `ft_format_char.c` - Handles `%c`, `%s`, `%%`
   - `ft_format_num.c` - Handles `%d`, `%i`, `%u`
   - `ft_format_hex.c` - Handles `%x`, `%X`, `%p`

5. **Flag Application** (applied in specific order):
   - `ft_apply_precision.c` - Applies precision to numbers/strings
   - `ft_apply_sign.c` - Applies `+` or space flag
   - `ft_apply_hash.c` - Applies `#` flag (0x prefix)
   - `ft_apply_width.c` - Applies field width with padding

### Key Data Structure

```c
typedef struct s_data {
    int     hash;      // # flag
    int     minus;     // - flag (left-justify)
    int     zero;      // 0 flag (zero-padding)
    int     plus;      // + flag (force sign)
    int     space;     // space flag
    int     width;     // field width
    int     is_prec;   // precision specified
    int     prec;      // precision value
    char    spec;      // conversion specifier
    char    *result;   // formatted output string
} t_data;
```

### Flag Precedence Rules

Implemented in `ft_apply_struct()`:
- `-` (minus) overrides `0` (zero-padding)
- `+` (plus) overrides ` ` (space)
- Application order: precision → sign → hash → width

### Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%p` - Pointer (hex with 0x prefix)
- `%d`, `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Lowercase hexadecimal
- `%X` - Uppercase hexadecimal
- `%%` - Literal percent sign

## Dependencies

- **libft**: Custom C standard library implementation located in `libft/` subdirectory
- Includes utility functions used throughout ft_printf (ft_strlen, ft_itoa, memory functions, etc.)

## Code Style

- 42 school norminette compliance required
- Headers must include the standard 42 header comment block
- No more than 25 lines per function
- Maximum 80 characters per line
