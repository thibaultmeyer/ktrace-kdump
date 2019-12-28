#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

int			main(int argc, char** argv)
{
  FILE*			fd;

  kd_setting_parser(argc, argv);
  fd = fopen(gl_settings.conf_inputfile, "r");
  if (fd)
    {
      kd_dump(fd);
      fclose(fd);
    }
  else
    perror("kdump");
  return (0);
}
