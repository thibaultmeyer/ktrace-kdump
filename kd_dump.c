#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>
#include "kdump.h"

static s_function_node	gl_function_ptr[] = {
  {KTR_SYSCALL, kd_dump_syscall},
  {KTR_SYSRET, kd_dump_sysret},
  {KTR_NAMEI, kd_dump_namei},
  {KTR_GENIO, kd_dump_genio},
  {KTR_PSIG, kd_dump_psig},
  {KTR_CSW, kd_dump_cswitch},
  {KTR_USER, kd_dump_userland}
};

static void	do_op(int type, void* data)
{
  int		i;

  i = 0;
  while (gl_function_ptr[i].type != 0)
    {
      if (gl_function_ptr[i].type == type)
	{
	  if (gl_function_ptr[i].my_function != NULL &&
	      IS_ENABLED(gl_settings.conf_flags, 1<<type))
	    gl_function_ptr[i].my_function(data);
	}
      i += 1;
    }
}

void			kd_dump(FILE* filedesc)
{
  struct ktr_header*	head;
  void*			data;

  data = (void*)malloc(sizeof(*head) + 1);
  while (kd_fread_loop(data, sizeof(*head), filedesc) > 0)
    {
      head = (struct ktr_header*)data;
      data = realloc(data, sizeof(*head) + head->ktr_len);
      kd_fread_loop(data + sizeof(*head), head->ktr_len, filedesc);
      if (gl_settings.conf_pid == 0 ||
	  gl_settings.conf_pid == (unsigned int)head->ktr_pid)
	do_op(head->ktr_type, data + sizeof(*head));
    }
  free(data);
}
