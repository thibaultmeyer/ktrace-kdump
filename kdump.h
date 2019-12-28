#ifndef _H_KDUMP_H_
# define _H_KDUMP_H_
# define	IS_ENABLED(var, mask)	(var & mask)

typedef enum	e_time_action
  {
    TIME_NONE = 0,
    TIME_ELAPSED,
    TIME_RELATIVE,
    TIME_ABSOLUTE
  }		t_showtime;

typedef struct  s_node_fct
{
  int		type;
  void          (*my_function)(void*);
}		s_function_node;

typedef struct	s_kdump_settings
{
  unsigned int		conf_dispdecimal;	/* -d */
  t_showtime		conf_displaytime;	/* -E -R -T */
  char			conf_inputfile[1024];	/* -f filename */
  unsigned int		conf_loopreading;	/* -l */
  unsigned int		conf_maxdata;		/* -m number */
  unsigned int		conf_suptranslation;	/* -n */
  unsigned int		conf_pid;		/* -p pid */
  unsigned int		conf_supiodisp;		/* -s */
  int			conf_flags;		/* -t cnisuw -> see ktrace */
  struct timeval	stat_tmptime;
  struct timeval	stat_prevtime;
}			t_kd_settings;

extern t_kd_settings	gl_settings;
extern const char*	unix_signal[];

char*           kd_mmap(int fd, unsigned int size);
int             kd_fread_loop(void* buffer, int size, FILE* fd);
unsigned int	kd_filesize(const char* path);
void		kd_dump(FILE* fd);

void		kd_dump_syscall(void* data);
void		kd_dump_sysret(void* data);
void		kd_dump_namei(void* data);
void		kd_dump_genio(void* data);
void		kd_dump_cswitch(void* data);
void		kd_dump_psig(void* data);
void		kd_dump_userland(void* data);

void		kd_hexdump(void* data, int len);
void		kd_get_term_size(int* w, int* h);
void		kd_printdump(void* data, int len);
void		kd_time(struct ktr_header* head);
void		kd_timevalsub(struct timeval *t1, const struct timeval *t2);

void		kd_help_show(int must_quit);
void		kd_setting_init(void);
void		kd_setting_parser(int argc, char** argv);

#endif
