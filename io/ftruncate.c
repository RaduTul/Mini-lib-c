// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/types.h>

int ftruncate(int fd, off_t length)
{
    /* TODO: Implement ftruncate(). */
    long aux =  syscall(__NR_ftruncate, fd, length);
    if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}