#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

void			kd_dump_userland(void* data)
{
  struct ktr_header*    head;
  char*                 tmp;
  char*			save;

  head = (struct ktr_header*)(data - sizeof(*head));
  tmp = (char*)malloc((sizeof(*tmp) * KTR_USER_MAXLEN + 1));
  memset(tmp, 0, KTR_USER_MAXLEN);
  strncpy(tmp, data, KTR_USER_MAXLEN);
  printf("%d ", head->ktr_len);
  save = tmp;
  for (;head->ktr_len > 0; head->ktr_len--)
    printf((gl_settings.conf_dispdecimal)? " %d" : " %02x", *(tmp++));
  printf("\n");
  free(save);
}
