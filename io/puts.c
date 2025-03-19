// SPDX-License-Identifier: BSD-3-Clause
#include <fcntl.h>
#include <internal/syscall.h>
#include <errno.h>
#include <stdio.h>
#include <internal/io.h>

size_t strlen(const char *str);
ssize_t write(int fd, const void *buf, size_t len);

int puts (const char *s) {
    int length = strlen(s);
    int aux = write(1, s, length);
    if (aux <= -1) {
        return -1;
    }
    aux = write(1, "\n", 1);
    if (aux <= -1) {
        return -1;
    }
    ++length;
    return length; 
}