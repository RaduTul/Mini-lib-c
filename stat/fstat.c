// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st) 
{   
    /* TODO: Implement close(). */
	long aux = syscall(__NR_fstat, fd, st);
	if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}