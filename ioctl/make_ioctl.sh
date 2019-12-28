#!/bin/sh
##
##	IOCTL REVERSE GENERATOR
##

## Begin
if [ -z "$1" ]; then
    echo "usage: sh $0 ioctl_inc_dir  (ie: sh $0 /usr/include/sys/)"
    exit 1
fi
PATH=$1
LOCAL=`pwd`
HEADER_FILE="ioctl_reverse.h"
SOURCE_FILE="ioctl_reverse.c"


## Check
cd $PATH
CHECK=`/bin/ls -s *.h | /usr/bin/grep "ioctl" | /usr/bin/wc -l | /usr/bin/awk '{print $1}'`
if [ $CHECK -lt 4 ]; then
    echo "Unable to find ioctl define in '$PATH'"
    exit 1
fi


## Header
echo "Generating header file"
cd $PATH
HEADER=""
HEADER=$HEADER"#ifndef _H_IOCTL_REVERSE_H_\n"
HEADER=$HEADER"# define _H_IOCTL_REVERSE_H_\n"
HEADER=$HEADER"# include <sys/param.h>\n# include <sys/devicestat.h>\n# include <sys/disklabel.h>\n# include <sys/socket.h>\n# include <sys/time.h>\n# include <sys/tty.h>\n# include <net/ethernet.h>\n# include <net/if.h>\n# include <net/if_var.h>\n# include <net/pfvar.h>\n# include <net/route.h>\n# include <netinet/in.h>\n# include <netinet/ip_mroute.h>\n# include <netinet6/in6_var.h>\n# include <netinet6/nd6.h>\n# include <netinet6/ip6_mroute.h>\n# include <stdio.h>\n# include <cam/cam.h>\n# include <sys/fbio.h>\n"
HEADER=$HEADER`/usr/bin/grep -r "_IO[a-zA-Z(]" . | /usr/bin/awk 'BEGIN{FS=":"}{FINAL[$1]++;}END{for (var in FINAL) {gsub("./", "", var); if (var != ""){print "# include <sys/"var">\\\n"}}}'`
HEADER=$HEADER"\nconst char*\tget_ioctl_define_name(u_long value);\n"
HEADER=$HEADER"\n#endif\n"
echo "Write file to hard drive"
cd $LOCAL
echo -e $HEADER > $HEADER_FILE

## Source
echo "Generating source file"
cd $PATH
SOURCE=""
SOURCE=$SOURCE"#include \""$HEADER_FILE"\"\n\n"
SOURCE=$SOURCE"const char*\tget_ioctl_define_name(u_long value)\n{\n"
SOURCE=$SOURCE`/usr/bin/grep -r "[A-Za-z_][A-Za-z0-9_	]_IO[a-zA-Z](" . | /usr/bin/awk 'BEGIN{FS=" "}{FINAL[$2]++;}END{i=0; for (var in FINAL) { if (!match(var, "_IO[A-Z]\\\(")) { if (i == 0 && var != ""){i=1; print "#if defined ("var")\\\nif (value == "var")\\\n\\\treturn (\""var"\");\\\n#endif\\\n" }else if(var != "") print "#if defined ("var")\\\nif (value == "var")\\\n\\\treturn (\""var"\");\\\n#endif\\\n"}}}'`
SOURCE=$SOURCE" \n\treturn (\"\");\n"
SOURCE=$SOURCE"}\n"
cd $LOCAL
echo "Write file to hard drive"
echo -e $SOURCE > $SOURCE_FILE
