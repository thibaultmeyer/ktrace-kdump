#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"
#include "syscalls.h"

const char*      unix_signal[] = {
  NULL, "HUP", "INT", "QUIT", "ILL", "TRAP", "ABRT", "EMT", "FPE", "KILL", "BUS",
  "SEGV", "SYS", "PIPE", "ALRM", "TERM", "URG", "STOP", "STP", "STOP", "CHLD",
  "TTIN", "TTOU", "IO", "XCPU", "XFSZ", "VTALRM", "PROF", "WINCH", "INFO",
  "USR1", "USR2", "THR"
};

void			kd_dump_psig(void* data)
{
  struct ktr_header*    head;
  struct ktr_psig*	psig;

  head = (struct ktr_header*)(data - sizeof(*head));
  psig = (struct ktr_psig*)data;
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  if (psig->action == SIG_DFL)
    printf("%-5s SIGINT SIG_DFL\n", "PSIG");
  else if (psig->signo > 32)
    printf("%-5s SIG %d caught handler=0x%x mask=0x%x code=0x%x\n",
	   "PSIG", psig->signo, (unsigned int)psig->action,
	   psig->mask.__bits[0], psig->code);
  else
    printf("%-5s SIG%s caught handler=0x%x mask=0x%x code=0x%x\n",
	   "PSIG", unix_signal[psig->signo],(unsigned int)psig->action,
	   psig->mask.__bits[0], psig->code);
}
