#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep (const struct timespec *req, struct timespec *rem)
{
	long aux = syscall(__NR_nanosleep, req, rem);
	if (aux <= -1) {
		errno = -aux;
		return -1;
	}
	return aux;
}