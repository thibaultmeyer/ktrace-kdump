#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"
#include "syscalls.h"

void			kd_dump_sysret(void* data)
{
  struct ktr_sysret*	sysret;
  struct ktr_header*	head;

  head = (struct ktr_header*)(data - sizeof(*head));
  sysret = (struct ktr_sysret*)data;
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  if (sysret->ktr_error != 0)
    {
      if (gl_settings.conf_suptranslation == 0)
	printf ("%-5s %s %d errno %d %s\n", "RET", syscallnames[sysret->ktr_code],
	    -1, sysret->ktr_error, strerror(sysret->ktr_error));
      else
	printf ("%-5s %s %d errno %d\n", "RET", syscallnames[sysret->ktr_code],
	    -1, sysret->ktr_error);
    }
  else
    {
      if (gl_settings.conf_suptranslation == 0)
	{
	  if (sysret->ktr_retval >= 0 && sysret->ktr_retval < 10)
	    printf ("%-5s %s %d\n", "RET", syscallnames[sysret->ktr_code],
		    sysret->ktr_retval);
	  else
	    printf ("%-5s %s %d/0x%x\n", "RET", syscallnames[sysret->ktr_code],
		    sysret->ktr_retval, sysret->ktr_retval);
	}
      else
	{
	  if (sysret->ktr_retval == 0)
	    printf ("%-5s %s %d\n", "RET", syscallnames[sysret->ktr_code],
		    sysret->ktr_retval);
	  else
	    printf ((gl_settings.conf_dispdecimal)?"%-5s %s %d\n":"%-5s %s 0x%x\n", "RET", syscallnames[sysret->ktr_code],
		    sysret->ktr_retval);
	}
    }
}
