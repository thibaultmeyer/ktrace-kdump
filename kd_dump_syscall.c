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
#include "syscalls.h"
#include "ioctl_reverse.h"

void			kd_dump_syscall(void* data)
{
  struct ktr_syscall*	syscall;
  struct ktr_header*    head;
  int			i;
  char			ioctl_name[255];

  head = (struct ktr_header*)(data - sizeof(*head));
  syscall = (struct ktr_syscall*)(data);
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  if (syscall->ktr_narg == 0)
    printf("%-5s %s\n", "CALL", syscallnames[syscall->ktr_code]);
  else
    {
      printf("%-5s %s(", "CALL", syscallnames[syscall->ktr_code]);
      for (i = 0; i < syscall->ktr_narg; ++i)
	{
	  if (i == 1 && strcmp(syscallnames[syscall->ktr_code], "ioctl") == 0 &&
	      gl_settings.conf_suptranslation == 0)
	    {
	      strcpy(ioctl_name, get_ioctl_define_name(syscall->ktr_args[i]));
	      if (strlen(ioctl_name) > 2)
		printf("%s", ioctl_name);
	      else
		printf((gl_settings.conf_dispdecimal) ? "%d" : "0x%x", syscall->ktr_args[i]);
	    }
	  else
	    {
	      if (syscall->ktr_args[i] != 0)
		printf((gl_settings.conf_dispdecimal) ? "%d" : "0x%x", syscall->ktr_args[i]);
	      else
		printf("%x", syscall->ktr_args[i]);
	    }
	  if (i + 1 != syscall->ktr_narg)
	    printf (",");
	}
      printf(")\n");
    }
}
