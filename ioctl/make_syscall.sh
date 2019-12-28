#!/bin/sh
##
##	SYSCALLS ARRAY GENERATOR
##
HEADER_FILE="syscalls.h"
SOURCE_FILE="syscalls.c"


## Write header file
HEADER="#ifndef _H_SYSCALLS_FILE_H_\n";
HEADER=$HEADER"# define _H_SYSCALLS_FILE_H_\n"
HEADER=$HEADER"\ntypedef struct		s_syscall_def\n"
HEADER=$HEADER"{\n"
HEADER=$HEADER"	int			code;\n"
HEADER=$HEADER"	const char*		type;\n"
HEADER=$HEADER"	const char*		name;\n"
HEADER=$HEADER"	int			nb_args;\n"
HEADER=$HEADER"}			t_syscall_def;\n"
HEADER=$HEADER"\n\nextern t_syscall_def	syscall_def[];\n"
HEADER=$HEADER"\n#endif\n"
echo -e $HEADER > $HEADER_FILE


## Create clean template
cat /usr/src/sys/kern/syscalls.master | awk '{if (index($0, '\n') && index($0, "\\")){printf "%s", $0}else{printf "%s\n",$0}}' | awk 'BEGIN{FS="{"; RS="}"}{print $1 $2}' | egrep "^[[:digit:]]" | tr -d "\\" > tmp.out


## Static data
SOURCE="#include \""$HEADER_FILE"\"\n\n"
SOURCE=$SOURCE"t_syscall_def	syscall_def[]={\n"
echo -e $SOURCE > $SOURCE_FILE


## Parse template & Print data
while read line
do
    nb_param=`echo $line | fold -w1 | grep "," | uniq -c | awk '{print $1}'`
    if [ ! -n "$nb_param" ]
    then
	check_one=`echo $line | awk 'BEGIN{FS="("; RS=")"}{print $2}' | grep "void"`
	if [ ! -n "$check_one" ]
	then
	    nb_param=1
	else
	    nb_param=0
	fi
    else
	nb_param=`expr $nb_param + 1`
    fi


    syscall_number=`echo $line | awk '{print $1}'`
    syscall_type=`echo $line | awk '{print $2}`
    syscall_name=`echo $line | awk '{print $4}' | awk 'BEGIN{FS="("}{print $1}'`
    if [ ! -n "$syscall_name" ]
    then
	syscall_name=`echo $line | awk '{print $3}'`
    fi


    ## Dump (append mode) into SOURCE file
    echo "{$syscall_number, \"$syscall_type\", \"$syscall_name\", $nb_param},"
    echo "{$syscall_number, \"$syscall_type\", \"$syscall_name\", $nb_param}," >> $SOURCE_FILE
done < "tmp.out"

## Close SOURCE file
SOURCE="};\n"
echo -e $SOURCE >> $SOURCE_FILE
