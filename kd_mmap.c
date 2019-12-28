#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

char*		kd_mmap(int fd, unsigned int size)
{
  char*		buffer;

  buffer = NULL;
  buffer = mmap(NULL, size, PROT_READ, MAP_FILE, fd, 0);
  if ((int)buffer == -1)
    {
      perror("mmap");
      return (NULL);
    }
  return (buffer);
}
