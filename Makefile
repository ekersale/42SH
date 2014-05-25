##
## Makefile for 42 in /home/thomps_j//42-true
## 
## Made by julien thompson
## Login   <thomps_j@epitech.net>
## 
## Started on  Tue May 14 22:50:24 2013 julien thompson
## Last update Fri May 31 23:37:35 2013 vincent thibaud
##

NAME	=	42sh

INCL	=	includes/

SRC	=					\
		sources/main.c			\
		sources/my_basics.c		\
		sources/my_getline.c		\
		sources/list_linker.c		\
		sources/xerror.c		\
		sources/get_env.c		\
		sources/get_his.c		\
		sources/get_glob.c		\
		sources/get_bin.c		\
		sources/cmd_translator.c	\
		sources/skip_func.c		\
		sources/set_standard.c		\
		sources/set_init.c		\
		sources/aff_prompt.c		\
		sources/core.c			\
		sources/executor.c		\
		sources/list_to_tab.c		\
		sources/built_in.c		\
		sources/bt_alias.c		\
		sources/bt_echo.c		\
		sources/bt_env.c		\
		sources/bt_exit.c		\
		sources/bt_history.c		\
		sources/bt_unsetenv.c		\
		sources/bt_setenv.c		\
		sources/my_cd.c			\
		sources/my_strcmp.c		\
		sources/cmd_to_list.c		\
		sources/list_to_conf.c		\
		sources/checking.c		\
		sources/is_separator.c		\
		sources/my_getinput.c		\
		sources/cmd_parser.c		\
		sources/cmd_pipe.c		\
		sources/cmd_pipe_exe.c		\
		sources/cmd_pipe_exe_multi.c	\
		sources/cmd_pipe_exe_out.c	\
		sources/cmd_wait_xor.c		\
		sources/cmd_exe.c		\
		sources/cmd_open_exe.c		\
		sources/cmd_open_parser.c


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -W -Werror -Wshadow -I $(INCL)

FLAGS	=	-lm

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(FLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
