#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "ktrace.h"

void                    check_exclusive(void)
{
  if (gl_settings.conf_pid > 0 && gl_settings.conf_pgid > 0)
    {
      printf("Arguments error : -p and -g switchs are mutually exclusive. Remove one of them !\n");
      exit(-1);
    }
}
