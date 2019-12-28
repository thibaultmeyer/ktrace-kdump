#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

static int	int_to_hex(int v)
{
  return (v & 0xFF);
}

void		kd_hexdump(void* data, int len)
{
  char*		buffer;
  int		cur;
  int		size;
  int		addr;
  int		max_print;

  kd_get_term_size(&size, NULL);
  if (size <= 10 || gl_settings.conf_suptranslation == 1)
    size = 80;
  buffer = (char*)data;
  size = (size - 13) / 4;
  if ((size % 2) == 0)
    --size;
  addr = 0;
  max_print = len;
  while (addr < len)
    {
      printf("       0x%04x ", addr);
      for (cur = 0; cur <= size; ++cur, ++addr)
	{
	  if (addr >= max_print || (gl_settings.conf_maxdata > 0 && (unsigned int)addr >= gl_settings.conf_maxdata))
	    printf("  ");
	  else
	    printf("%02x", int_to_hex(buffer[addr]));
	  if ((cur % 2))
	    printf(" ");
	}
      printf("  |");
      for (cur = (addr - size - 1); cur < addr; ++cur)
	{
	  if (cur >= max_print || (gl_settings.conf_maxdata > 0 && (unsigned int)cur >= gl_settings.conf_maxdata))
	    break;
	  if (buffer[cur] > 31 && buffer[cur] < 127)
	    printf("%c", buffer[cur]);
	  else
	    printf(".");
	}
      printf("|");
      printf("\n");
      if (gl_settings.conf_maxdata > 0 && (unsigned int)cur >= gl_settings.conf_maxdata)
	break;
    }
  printf("\n");
}
