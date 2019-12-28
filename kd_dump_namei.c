#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

void			kd_dump_namei(void* data)
{
  struct ktr_header*    head;
  char*			tmp;

  head = (struct ktr_header*)(data - sizeof(*head));
  tmp = (char*)malloc((sizeof(*tmp) * head->ktr_len  + 1));
  strncpy(tmp, data, head->ktr_len);
  tmp[head->ktr_len] = '\0';
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  printf ("%-5s \"%s\"\n", "NAMI", tmp);
  free(tmp);
}
