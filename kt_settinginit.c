#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/ktrace.h>
#include "ktrace.h"

t_kt_settings    gl_settings;

void                    setting_init(void)
{
  memset(gl_settings.conf_outputfile, 0, 4096);
  strncpy(gl_settings.conf_outputfile, "./ktrace.out", 12);
  gl_settings.conf_nb_args = 1;
  gl_settings.conf_traceflags = 0;
  gl_settings.conf_pid = 0;
  gl_settings.conf_pgid = 0;
  gl_settings.conf_disable_all = 0;
  gl_settings.conf_openmode = O_WRONLY | O_TRUNC | O_CREAT;
  gl_settings.conf_option = KTROP_SET;
}
