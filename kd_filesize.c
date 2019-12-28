#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

unsigned int    kd_filesize(const char* path)
{
  struct stat	sb;

  if (-1 == stat(path, &sb))
    perror("stat");
  else
    return (sb.st_size);
  return (0);
}
