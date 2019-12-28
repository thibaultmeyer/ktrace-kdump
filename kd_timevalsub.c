#include <sys/time.h>

static void	kd_timevalfix(struct timeval *t1)
{
  if (t1->tv_usec < 0)
    {
      t1->tv_sec--;
      t1->tv_usec += 1000000;
    }
  if (t1->tv_usec >= 1000000)
    {
      t1->tv_sec++;
      t1->tv_usec -= 1000000;
    }
}

void	kd_timevalsub(struct timeval *t1, const struct timeval *t2)
{
  t1->tv_sec -= t2->tv_sec;
  t1->tv_usec -= t2->tv_usec;
  kd_timevalfix(t1);
}
