#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "ktrace.h"

int		main(int argc, char** argv)
{
  int		fd = 0;
  int		nb = 0;

  if (argc < 2)
    help_show(0);
  else
    {
      setting_parser(argc, argv);
      check_exclusive();
      if (gl_settings.conf_disable_all == 0)
	fd = open(gl_settings.conf_outputfile, gl_settings.conf_openmode, 0666);
      if (fd > 0)
	close(fd);
      if (gl_settings.conf_pid > 0 || gl_settings.conf_pgid > 0)
	{
	  if (-1 == ktrace(gl_settings.conf_outputfile, gl_settings.conf_option,
			   gl_settings.conf_traceflags,
			   gl_settings.conf_pid > 0 ? gl_settings.conf_pid : gl_settings.conf_pgid))
	    {
	      perror("ktrace");
	      exit(-2);
	    }
	}
      else
	{
	  nb = argc - gl_settings.conf_nb_args;
	  if (nb <= 0 && gl_settings.conf_disable_all == 0)
	    help_show(1);
	  if (-1 == ktrace(gl_settings.conf_outputfile, gl_settings.conf_option,
			   gl_settings.conf_traceflags, getpid()))
	    {
	      perror("ktrace");
	      exit(-2);
	    }
	  if (gl_settings.conf_disable_all == 0)
	    if (-1 == execvp(argv[gl_settings.conf_nb_args], &argv[gl_settings.conf_nb_args]))
	      perror("execvp");
	}
      exit(0);
    }
  return (0);
}
