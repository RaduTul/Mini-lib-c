# Mini-libc

## Objectives
- Understand the structure and functionalities of the standard C library.
- Get familiar with the Linux syscall interface.
- Improve knowledge of string and memory management functions.
- Learn how the standard C library supports low-level input/output operations.

## Statement
Build a minimalistic [standard C library](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems, named **mini-libc**. This library will serve as a replacement for the system libc (glibc in Linux) and will provide essential functionalities such as string management, basic memory support, and POSIX file I/O.

The **mini-libc** implementation will be freestanding, meaning it will not use external library calls. It will be based on the system call interface provided by Linux on an **x86_64** architecture. Any required functions from libc must be implemented manually, and previously implemented functions can be reused in other parts of the mini-libc.

For macOS users with **ARM64 / Aarch64**, an **x86_64 virtual machine** must be installed to complete the assignment.

## Support Code
The project consists of three main directories:
- **libc/** – The skeleton mini-libc implementation, where missing parts must be implemented.
- **samples/** – Contains use cases and test examples for mini-libc.
- **tests/** – Includes tests for validating and grading the implementation.

System call invocation is handled by the `syscall()` function in `libc/syscall.c`, which relies on the architecture-specific implementation in `libc/internal/arch/x86_64/syscall_arch.h`.

## API and Implementation Tasks
### Required Headers and Functions
#### `<string.h>` – String-handling functions
- `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`
- `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
- `memcpy()`, `memset()`, `memmove()`, `memcmp()`

#### `<stdio.h>` – Printing and I/O functions
- `puts()`

#### `<unistd.h>`, `<sys/fcntl.h>`, `<sys/stat.h>` – I/O primitives
- `open()`, `close()`, `lseek()`, `stat()`, `fstat()`
- `truncate()`, `ftruncate()`
- `nanosleep()`, `sleep()`

#### `<stdlib.h>`, `<sys/mman.h>` – Memory allocation functions
- `malloc()`, `free()`, `calloc()`, `realloc()`, `realloc_array()`
- `mmap()`, `mremap()`, `munmap()`

#### `<errno.h>` – Error handling
- The `errno` variable must be properly modified by certain functions.

### Additional Tasks
Some tests will not compile initially due to missing components. To fix this, the following items must be implemented:
- `time.h` header
- `puts()` function
- `nanosleep()` and `sleep()` functions
- Update the **libc Makefile** to include the above functions.

## Building Mini-libc
To build **mini-libc**, navigate to the `libc/` directory and run:
```sh
cd libc/
make
```

To build the **samples**, navigate to the `samples/` directory and run:
```sh
cd samples/
make
```

## Testing and Grading
The **tests/** directory contains automated tests.
To list available tests:
```sh
ls -F tests/
```

To run all tests and check the implementation:
```sh
cd tests/
make check
```

The total number of points available is **900**, with the maximum possible grade being **90** (points divided by 10).

### Expected Output
Initially, many tests will fail due to missing implementations. A successful run should display passing tests, such as:
```sh
test_strcpy                      ........................ passed ..   9
test_memcpy                      ........................ passed ..  11
test_open_non_existent_file      ........................ passed ..   8
test_sleep                       ........................ passed ..  20
```

To achieve full marks, all required functions must be correctly implemented and tested.

## Notes
- Some files will fail to build initially. This is expected and will be resolved as missing functions are implemented.
- Many tests will initially fail due to missing functionality.
- Pay attention to functions that modify `errno`.

By completing this assignment, you will gain hands-on experience with **low-level C programming**, **memory management**, and **system calls** in Linux.

