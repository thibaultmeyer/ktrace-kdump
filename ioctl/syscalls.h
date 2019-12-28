#ifndef _H_SYSCALLS_FILE_H_
# define _H_SYSCALLS_FILE_H_

typedef struct s_syscall_def
{
 int code;
 const char* type;
 const char* name;
 int nb_args;
} t_syscall_def;


extern t_syscall_def syscall_def[];

#endif

