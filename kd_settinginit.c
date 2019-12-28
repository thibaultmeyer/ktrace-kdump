#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

t_kd_settings	gl_settings;

void            kd_setting_init(void)
{
  memset(gl_settings.conf_inputfile, 0 , 1024);
  strncpy(gl_settings.conf_inputfile, "ktrace.out", 10);
  gl_settings.conf_pid = 0;
  gl_settings.conf_flags = 0;
  gl_settings.conf_maxdata = 0;
  gl_settings.conf_supiodisp = 0;
  gl_settings.conf_dispdecimal = 0;
  gl_settings.conf_loopreading = 0;
  gl_settings.conf_displaytime = TIME_NONE;
  gl_settings.conf_suptranslation = 0;
  gl_settings.stat_tmptime.tv_sec = 0;
  gl_settings.stat_tmptime.tv_usec = 0;
  gl_settings.stat_prevtime.tv_sec = 0;
  gl_settings.stat_prevtime.tv_usec = 0;
}
