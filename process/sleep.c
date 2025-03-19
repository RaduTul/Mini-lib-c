#include <time.h>
#include <errno.h>
#include <internal/types.h>

int sleep (unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = (uint64_t) seconds;
    req.tv_nsec = 0;
    while (1) {
        if (nanosleep(&req, &rem) == 0) {
            return 0;
        } else if (errno != EINTR) {
            break;
        }
    }
    return -1;
}