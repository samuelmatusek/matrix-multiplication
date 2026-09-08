# Dynamic 2D Matrix Multiplication in C

A CLI application written in pure C that dynamically allocates, multiplies, and frees two 2D matrices of arbitrary valid dimensions.

## Features

- **Dynamic Memory Management:** Uses 2D pointer arrays (`int**`) with full dynamic allocation (`malloc`) and proper deallocation (`free`).
- **Memory Safety:** Safe partial-allocation cleanups to prevent leaks if memory allocation fails mid-process.
- **Input Validation:** Verifies matrix compatibility (columns of $A$ equal rows of $B$), valid dimensions ($> 0$), and input types.
- **Leak-Free:** Tested and verified with Valgrind (`0 errors, 0 memory leaks`).

## Mathematical Requirement

Given matrix $A$ of size $R_A \times S_A$ and matrix $B$ of size $R_B \times S_B$, the multiplication $C = A \cdot B$ is valid if and only if:

$$S_A = R_B$$

The resulting matrix $C$ will have dimensions $R_A \times S_B$.

## How to Build and Run

### 1. Compilation
Compile with standard strict flags:
```bash
gcc -Wall -pedantic -g nasobeniDvouMatic.c -o matrix_mul
```

### 2. Execution
```bash
./matrix_mul
```

### 3. Check for Memory Leaks (Valgrind)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./matrix_mul
```

## Example Usage

```text
Zadej rozmery matice A (radky sloupce):
2 3
Zadejte prvky matice A:
1 2 3
4 5 6
Zadej rozmery matice B (radky sloupce):
3 2
Zadejte prvky matice B:
7 8
9 1
2 3
Vysledna matice:
31 19
85 55
```
