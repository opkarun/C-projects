# C-projects
# Custom C Printf Implementation (`karunf`)

A lightweight, from-scratch implementation of the standard C `printf` function. This project was built to explore low-level memory management, variadic functions, and the "essence" of data transformation in C.

## 🚀 Key Features

*   **Variadic Argument Handling**: Custom stack navigation using `stdarg.h`.
*   **Format Specifiers Supported**:
    *   `%c`: Single character.
    *   `%s`: Strings (with **Null-pointer protection** printing `(null)`).
    *   `%d` / `%i`: Signed integers (with overflow-safe `INT_MIN` handling).
    *   `%%`: Literal percent sign.
*   **Memory Efficiency**: Direct use of `putchar` for low-level character output.

## 🧠 Technical Deep Dive

### Handling `INT_MIN` Safely
Standard 32-bit signed integers range from -2,147,483,648 to 2,147,483,647. Converting `-2147483648` to a positive value directly causes an overflow. My implementation uses the two's complement identity:
`unsigned int value = (unsigned int)-(real + 1) + 1;`
This ensures the smallest possible integer is handled with **architectural stability**.

### Pointer Arithmetic vs. Indexing
For the `%s` implementation, I utilized **pointer arithmetic** (`*str++`) to navigate memory. This is more idiomatic in C and often more efficient than repeated array indexing.

## 🛠️ Compilation & Usage

Compile using `gcc` with strict flags to ensure production-grade code:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o karunf

