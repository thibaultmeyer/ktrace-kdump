NAME_KT		=	ktrace
NAME_KD		=	kdump
CC		=	gcc
RM		=	rm -f
SRC_KT		+=	kt_main.c		\
			kt_checkexclusive.c	\
			kt_helpshow.c		\
			kt_settinginit.c	\
			kt_settingparser.c
SRC_KD		+=	kd_dump.c		\
			kd_dump_cswitch.c	\
			kd_dump_genio.c		\
			kd_dump_namei.c		\
			kd_dump_psig.c		\
			kd_dump_syscall.c	\
			kd_dump_sysret.c	\
			kd_dump_userland.c	\
			kd_filesize.c		\
			kd_freadloop.c		\
			kd_gettermsize.c	\
			kd_helpshow.c		\
			kd_hexdump.c		\
			kd_main.c		\
			kd_mmap.c		\
			kd_printdump.c		\
			kd_settinginit.c	\
			kd_settingparser.c	\
			kd_time.c		\
			kd_timevalsub.c		\
			ioctl_reverse.c		\
			syscalls.c
OBJ_KT		=	$(SRC_KT:.c=.o)
OBJ_KD		=	$(SRC_KD:.c=.o)
CFLAGS		=	-ansi -Wall -W -Wstrict-prototypes

all		:
	@make $(NAME_KT)
	@make $(NAME_KD)

ioctl_reverse.c	:	${.CURDIR}/Makefile ${.CURDIR}/make_ioctl.sh
	@/bin/sh make_ioctl.sh /usr/include/sys

$(NAME_KT)		:	$(OBJ_KT)
	$(CC) $(OBJ_KT) -o $(NAME_KT)

$(NAME_KD)		:	ioctl_reverse.c $(OBJ_KD)
	$(CC) $(OBJ_KD) -o $(NAME_KD)

ioctl		:	ioctl_reverse.c

clean		:
	$(RM) $(OBJ_KT)
	$(RM) $(OBJ_KD)

fclean		:	clean
	$(RM) $(NAME_KT)
	$(RM) $(NAME_KD)
	$(RM) ioctl_reverse.c
	$(RM) ioctl_reverse.h

re		:	fclean all
