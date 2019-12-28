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

int		setting_parser(int argc, char** argv)
{
  int		c;
  unsigned int	i;

  setting_init();
  while ((c = getopt(argc, argv, "if:t:p:g:adChc:")) != -1)
    {
      switch (c)
	{
	case 'h':
	  help_show(1);
	  break;
	case 'f':
	  ++gl_settings.conf_nb_args;
	  if (argv[gl_settings.conf_nb_args -1][2] == '\0')
	    ++gl_settings.conf_nb_args;
	  memset(gl_settings.conf_outputfile, 0, strlen(gl_settings.conf_outputfile) + 2);
	  strncpy(gl_settings.conf_outputfile, optarg, 4096);
	  break;
	case 't':
	  ++gl_settings.conf_nb_args;
	  if (argv[gl_settings.conf_nb_args -1][2] == '\0')
	    ++gl_settings.conf_nb_args;
	  for (i = 0; i < strlen(optarg); ++i)
	    {
	      if (optarg[i] == 'c')
		gl_settings.conf_traceflags |= KTRFAC_SYSCALL;
	      else if (optarg[i] == 'n')
		gl_settings.conf_traceflags |= KTRFAC_NAMEI;
	      else if (optarg[i] == 'i')
		gl_settings.conf_traceflags |= KTRFAC_GENIO;
	      else if (optarg[i] == 's')
		gl_settings.conf_traceflags |= KTRFAC_PSIG;
	      else if (optarg[i] == 'u')
		gl_settings.conf_traceflags |= KTRFAC_USER;
	      else if (optarg[i] == 'w')
		gl_settings.conf_traceflags |= KTRFAC_CSW;
	      else if (optarg[i] == '+')
		{
		  gl_settings.conf_traceflags |= KTRFAC_SYSCALL;
		  gl_settings.conf_traceflags |= KTRFAC_NAMEI;
		  gl_settings.conf_traceflags |= KTRFAC_GENIO;
		  gl_settings.conf_traceflags |= KTRFAC_PSIG;
		  gl_settings.conf_traceflags |= KTRFAC_USER;
		}
	    }
	  break;
	case 'p':
	  ++gl_settings.conf_nb_args;
	  gl_settings.conf_pid = (unsigned int)atoi(optarg);
	  break;
	case 'g':
	  ++gl_settings.conf_nb_args;
	  gl_settings.conf_pgid = (unsigned int)atoi(optarg);
	  break;
	case 'a':
	  if (argv[gl_settings.conf_nb_args][1] == 'a')
	    ++gl_settings.conf_nb_args;
	  gl_settings.conf_openmode = O_WRONLY | O_APPEND;
	  break;
	case 'C':
	  if (argv[gl_settings.conf_nb_args][1] == 'C')
	    ++gl_settings.conf_nb_args;
	  gl_settings.conf_disable_all = 1;
	  gl_settings.conf_traceflags = KTRFAC_SYSCALL | KTRFAC_NAMEI | KTRFAC_GENIO | KTRFAC_PSIG| KTRFAC_USER| KTRFAC_CSW;
	  gl_settings.conf_option |= KTROP_CLEAR;
	  gl_settings.conf_pid = 1;
	  break;
	case 'i':
	  if (argv[gl_settings.conf_nb_args][1] == 'i')
	    ++gl_settings.conf_nb_args;
	  gl_settings.conf_traceflags |= KTRFAC_INHERIT;
	  break;
	case 'd':
	  if (argv[gl_settings.conf_nb_args][1] == 'd')
	    ++gl_settings.conf_nb_args;
	  gl_settings.conf_option |= KTRFLAG_DESCEND;
	  break;
	case 'c':
	  if (argv[gl_settings.conf_nb_args][1] == 'c')
	    ++gl_settings.conf_nb_args;
	  gl_settings.conf_disable_all = 1;
	  gl_settings.conf_option |= KTROP_CLEAR;
	  gl_settings.conf_pid = (unsigned int)atoi(optarg);
	  break;
	default:
	  break;
	}
    }
  if (gl_settings.conf_traceflags == 0)
    gl_settings.conf_traceflags = KTRFAC_SYSCALL | KTRFAC_NAMEI | KTRFAC_GENIO | KTRFAC_PSIG | KTRFAC_USER | KTRFAC_SYSRET;
  else if (gl_settings.conf_traceflags && 1<<KTR_SYSRET)
    gl_settings.conf_traceflags |= KTRFAC_SYSRET;
  return (1);
}
