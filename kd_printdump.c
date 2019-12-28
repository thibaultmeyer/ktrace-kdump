#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

void		kd_printdump(void* data, int len)
{
  char*		buffer;
  char*		save;
  char*		final;
  char		tmp[5];
  int		max_print;
  int		width, w;
  int		column;

  kd_get_term_size(&width, NULL);
  if (width <= 10 || gl_settings.conf_suptranslation == 1)
    width = 80;
  max_print = len;
  buffer = malloc((sizeof(*buffer) * len) + 1);
  buffer = memset(buffer, 0, len);
  strncpy(buffer, data, len);
  save = buffer;
  column = 8;
  w = 1;
  printf("       \"");
  if (gl_settings.conf_maxdata > 0 &&
      gl_settings.conf_maxdata < (unsigned int)len)
    len = gl_settings.conf_maxdata;
  for (;len > 0; --len, ++buffer)
    {
      tmp[0] = *buffer;
      tmp[1] = '\0';
      final = tmp;
      if (column == 0)
	{
	  column = 8;
	  printf("\t");
	}
      if (*final == '\n')
	{
	  column = 0;
	  if (*(final + 1) != '\0')
	    printf("\n");
	}
      else if (*final == '\t')
	w = 8 - (column & 07);
      else
	w = strlen(final);
      if (column + w > (width - 2))
	{
	  printf("\\\n\t");
	  column = 8;
	}
      column += w;
      printf("%s", final);
    }
  if (*(buffer-1) == '\n')
    printf("       ");
  printf("\"\n");
  free(save);
}
