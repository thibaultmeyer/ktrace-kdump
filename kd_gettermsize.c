#include <stdlib.h>
#include <sys/ioctl.h>

void			kd_get_term_size(int* w, int* h)
{
  struct winsize	win;

  if (w != NULL)
    *w = 0;
  if (h != NULL)
    *h = 0;
  if (ioctl (0, TIOCGWINSZ, &win) >= 0)
    {
      if (w != NULL)
	*w = win.ws_col;
      if (h != NULL)
	*h = win.ws_row;
    }
}
