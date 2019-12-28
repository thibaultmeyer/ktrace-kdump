#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

void            kd_setting_parser(int argc, char** argv)
{
  int		c;
  unsigned int	i;

  kd_setting_init();
  while ((c = getopt(argc, argv, "dEf:hlm:np:RsTt:")) != -1)
    {
      switch (c)
	{
	case 'd':
	  gl_settings.conf_dispdecimal = 1;
	  break;
	case 'E':
	  gl_settings.conf_displaytime = TIME_ELAPSED;
	  break;
	case 'f':
	  memset(gl_settings.conf_inputfile, 0, 1024);
	  strncpy(gl_settings.conf_inputfile, optarg, 1024);
	  break;
	case 'h':
	  kd_help_show(1);
	  break;
	case 'l':
	  gl_settings.conf_loopreading = 1;
	  break;
	case 'm':
	  gl_settings.conf_maxdata = (unsigned int)atoi(optarg);
	  break;
	case 'n':
	  gl_settings.conf_suptranslation = 1;
	  break;
	case 'p':
	  gl_settings.conf_pid = (unsigned int)atoi(optarg);
	  break;
	case 'R':
	  gl_settings.conf_displaytime = TIME_RELATIVE;
	  break;
	case 's':
	  gl_settings.conf_supiodisp = 1;
	  break;
	case 'T':
	  gl_settings.conf_displaytime = TIME_ABSOLUTE;
	  break;
	case 't':
	  for (i = 0; i < strlen(optarg); ++i)
	    {
	      if (optarg[i] == 'c')
		gl_settings.conf_flags |= KTRFAC_SYSCALL;
	      else if (optarg[i] == 'n')
		gl_settings.conf_flags |= KTRFAC_NAMEI;
	      else if (optarg[i] == 'i')
		gl_settings.conf_flags |= KTRFAC_GENIO;
	      else if (optarg[i] == 's')
		gl_settings.conf_flags |= KTRFAC_PSIG;
	      else if (optarg[i] == 'u')
		gl_settings.conf_flags |= KTRFAC_USER;
	      else if (optarg[i] == 'w')
		gl_settings.conf_flags |= KTRFAC_CSW;
	      else if (optarg[i] == '+')
		{
		  gl_settings.conf_flags |= KTRFAC_SYSCALL;
		  gl_settings.conf_flags |= KTRFAC_NAMEI;
		  gl_settings.conf_flags |= KTRFAC_GENIO;
		  gl_settings.conf_flags |= KTRFAC_PSIG;
		  gl_settings.conf_flags |= KTRFAC_USER;
		}
	    }
	  break;
	}
    }
  if (gl_settings.conf_flags == 0)
    gl_settings.conf_flags = KTRFAC_SYSCALL | KTRFAC_NAMEI | KTRFAC_GENIO | KTRFAC_PSIG | KTRFAC_USER | KTRFAC_SYSRET;
  else if (IS_ENABLED(gl_settings.conf_flags, 1<<KTR_SYSCALL))
    gl_settings.conf_flags |= KTRFAC_SYSRET;
}
