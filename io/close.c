// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	long aux = syscall(__NR_close, fd);
	if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}