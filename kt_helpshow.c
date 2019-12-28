#include <stdio.h>
#include <stdlib.h>

void		help_show(int must_quit)
{
  printf("Usage :  ./ktrace [-a] [-h] [-i] [-d] [-C] [-t cnisuw] [-f filename.out] [-c pid] [-p pid] [-g gid] command\n" \
	 "\n"
	 "\t-a \t Append mode\n"					\
	 "\t-c \t Disable tracing on specified processe ID\n"		\
	 "\t-C \t Disable tracing on all user owned processes\n"	\
	 "\t-d \t Descent to all current children\n"			\
	 "\t-f \t Change output filename (default : ktrace.out)\n"	\
	 "\t-g \t Trace all PID in the process group\n"			\
	 "\t-h \t Show this help page\n"				\
	 "\t-i \t Inherit to all future children\n"			\
	 "\t-p \t Trace only indicated PID Process\n"			\
	 "\t-t \t The kernel trace points, one per letter\n"		\
	 "\t\t\tc \t Trace System Call\n"				\
	 "\t\t\tn \t Trace namei translations\n"			\
	 "\t\t\ti \t Trace I/O\n"					\
	 "\t\t\ts \t Trace signal processing\n"				\
	 "\t\t\tu \t Trace userland traces\n"				\
	 "\t\t\tw \t Trace context switches\n"				\
	 "\t\t\t+ \t Trace the default set of trace points - c, n, i, s, u\n" \
	 "\n"								\
	 "\tThe -p, -g, and command options are mutually exclusive.\n");
  if (must_quit != 0)
    exit(-1);
}
