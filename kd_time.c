#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

void		kd_time(struct ktr_header* head)
{
  if (gl_settings.conf_displaytime != TIME_NONE)
    {
      if (gl_settings.conf_displaytime == TIME_ELAPSED)
	{
	  if (gl_settings.stat_prevtime.tv_sec == 0)
	    gl_settings.stat_prevtime = head->ktr_time;
	  kd_timevalsub(&head->ktr_time, &gl_settings.stat_prevtime);
	}
      if (gl_settings.conf_displaytime == TIME_RELATIVE)
	{
	  gl_settings.stat_tmptime = head->ktr_time;
	  kd_timevalsub(&head->ktr_time, &gl_settings.stat_prevtime);
	  gl_settings.stat_prevtime = gl_settings.stat_tmptime;
	}
      printf("%jd.%06ld ", (intmax_t)head->ktr_time.tv_sec, head->ktr_time.tv_usec);
    }
}
