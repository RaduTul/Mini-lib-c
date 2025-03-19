// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long aux =  syscall(9, addr, length, prot, flags, fd, offset);
	if(aux <= -1) {
		errno = -aux;
		return (void*)(-1);
	}
	return (void*)(aux);
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long aux =  syscall(25, old_address, old_size, new_size, flags);
	if(aux <= -1) {
		errno = -aux;
		return (void*)(-1);
	}
	return (void*)(aux);
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long aux =  syscall(11, addr, length);
	if(aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}
