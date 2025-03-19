// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	long aux = syscall(__NR_truncate, path, length);
	if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}