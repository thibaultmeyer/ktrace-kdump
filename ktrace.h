#ifndef _H_KTRACE_H_
# define _H_KTRACE_H_

typedef struct		s_ktrace_settings
{
  unsigned int		conf_nb_args;
  char			conf_outputfile[4096];	/* -f */
  unsigned int		conf_traceflags;	/* -t cnisuw+ */
  unsigned int		conf_pid;		/* -p */
  unsigned int		conf_pgid;		/* -g */
  unsigned short	conf_openmode;		/* -a */
  unsigned int		conf_option;
  unsigned int		conf_disable_all;	/* -C */
}			t_kt_settings;

extern t_kt_settings	gl_settings;

void			check_exclusive(void);
void			help_show(int must_quit);
void			setting_init(void);
int			setting_parser(int argc, char** argv);

#endif
