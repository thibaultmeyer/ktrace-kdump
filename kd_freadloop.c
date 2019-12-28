#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

int		kd_fread_loop(void* buffer, int size, FILE* fd)
{
  int		ret;

  while ((ret = fread(buffer, size, 1, fd)) == 0 &&
	 gl_settings.conf_loopreading)
    sleep(1);
  return (ret);
}
