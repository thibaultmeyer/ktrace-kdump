#include <stdio.h>
#include <stdlib.h>

void		kd_help_show(int must_quit)
{
  printf("Usage :  ./kdump [-dEnlRsT] [-f trfile] [-m maxdata] [-p pid] [-t [cnisuw]]\n" \
	 "\n"
	 "\t-d \t Display all numbers in decimal\n"			\
	 "\t-E \t Display elapsed timestamps (beginning of trace)\n"	\
	 "\t-n \t Suppress ad hoc translations\n"			\
	 "\t-l \t Loop reading the trace file, wait at end...\n"	\
	 "\t-R \t Display relative timestamps (since previous entry)\n"	\
	 "\t-s \t Suppress display of I/O data\n"			\
	 "\t-T \t Display absolute timestamps for each entry (since epoch)\n" \
	 "\t-f \t Display the specified file instead of ktrace.out\n"	\
	 "\t-m \t Display at most maxdata bytes when decoding I/O\n"	\
	 "\t-t \t The kernel trace points, one per letter\n"		\
	 "\t\t\tc \t Display System Call\n"				\
	 "\t\t\tn \t Display namei translations\n"			\
	 "\t\t\ti \t Display I/O\n"					\
	 "\t\t\ts \t Display signal processing\n"			\
	 "\t\t\tu \t Display userland traces\n"				\
	 "\t\t\tw \t Display context switches\n"			\
	 "\t\t\t+ \t Display the default set of trace points - c, n, i, s, u\n");
  if (must_quit != 0)
    exit(-1);
}
