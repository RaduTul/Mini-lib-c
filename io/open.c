// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
    long aux =  syscall(__NR_open, filename, flags);
	if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}