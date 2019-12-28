#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"
#include "syscalls.h"

void			kd_dump_cswitch(void* data)
{
  struct ktr_header*    head;
  struct ktr_csw*	csw;

  head = (struct ktr_header*)(data - sizeof(*head));
  csw = (struct ktr_csw*)data;
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  printf("%-5s %s %s\n", "CSW", (csw->out) ? "out":"in", (csw->user) ? "user":"kernel");
}
