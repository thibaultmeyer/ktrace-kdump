#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"
#include "syscalls.h"

void			kd_dump_genio(void* data)
{
  struct ktr_header*    head;
  struct ktr_genio*	genio;
  char*			buffer;
  int			datalen;
  int			i ;
  int			is_binary;

  is_binary = 0;
  head = (struct ktr_header*)(data - sizeof(*head));
  genio = (struct ktr_genio*)data;
  buffer = (char*)(data + sizeof(*genio));
  datalen = head->ktr_len - sizeof(struct ktr_genio);
  printf(" %d %-8s ", head->ktr_pid, head->ktr_comm);
  kd_time(head);
  if (genio->ktr_rw == 0)
    printf("%-5s fd %d read %d byte%s\n", "GIO", genio->ktr_fd, datalen, datalen == 1 ? "" : "s");
  else
    printf("%-5s fd %d wrote %d byte%s\n", "GIO", genio->ktr_fd, datalen, datalen == 1 ? "" : "s");
  if (gl_settings.conf_supiodisp == 0)
    {
      for (i = 0; i < datalen; ++i)
	if (buffer[i] < 32 && buffer[i] != 0 && buffer[i] != 10 &&
	    buffer[i] != 13 && buffer[i] != '\t')
	  {
	    is_binary = 1;
	    break;
	  }
      (is_binary == 1 ) ? kd_hexdump(buffer, datalen) :  kd_printdump(buffer, datalen);
    }
}
