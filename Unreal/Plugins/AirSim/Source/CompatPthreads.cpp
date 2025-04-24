// CompatPthreads.cpp
#include <pthread.h>

extern "C" int pthread_cond_clockwait(pthread_cond_t *cond,
                                      pthread_mutex_t *mutex,
                                      const struct timespec *timeout) {
    // CentOS7 glibc 没有 pthread_cond_clockwait，
    // 用 pthread_cond_timedwait 代替：
    return pthread_cond_timedwait(cond, mutex, timeout);
}

