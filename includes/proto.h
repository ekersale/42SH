/*
** proto.h for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 15 01:05:32 2013 julien thompson
** Last update Fri May 31 23:22:54 2013 vincent thibaud
*/

#ifndef		_PROTO_H__
# define	_PROTO_H__

# include	"types.h"

/*
** CHECKING
*/
int		check_redir(t_his *);
int		check_cmd(t_conf *);

/*
** CHECKING
*/
int		cmd_translator(char *, t_data *);

/*
** CMD_TO_LIST
*/
char		*word_inhib(char *, int *, char);
char		*concat_separ(char *, t_his *);
char		*concat_word(char *, int, t_his *);
int		word_len(char *);
t_his		*cmd_to_list(char *);

/*
** IS_SEPARATOR
*/
int		is_separator(char *);

/*
** CHECKING
*/
int		word_to_separ(t_his *);
int		concat_redir(t_his **, t_conf *, int);
void		set_link(t_his **, t_conf *, int);
t_his		*concat_list(t_his *, t_conf *);
int		list_to_conf(t_data *, t_his *);

/*
** SKIP_FUNC
*/
void		skip_text(char **);
void		skip_void(char **);
void		skip_word(char **);

/*
** GET_LINE
*/
char            *cmb_str(char *, char *);

/*
** AFF_PROMPT
*/
void            get_sigint(int);
void		aff_prompt(t_data *);
void		aff_small_pwd(char *);

/*
** BUILT_IN (ALL)
*/
int		is_buit_in(t_data *, char *);
int		call_built_in(t_data *, char **);
int		bt_alias(t_data *, char **);
int		check_cd(t_data *, char **);
int		bt_echo(t_data *, char **);
int		bt_env(t_data *, char **);
int		bt_exit(t_data *, char **);
int		bt_history(t_data *, char **);
void		aff_his_num(t_his *);
int		bt_setenv(t_data *, char **);
int		new_env_var(t_data *, char *, char *);
void		remove_env_var(t_data *, char *);
int		bt_unsetenv(t_data *, char **);

/*
** CORE
*/
int		core(t_data *);
char		*prompt_and_input(t_data *);
void		exec_manager(t_data *);

/*
** EXECUTOR
*/
int		uni_executor(t_data *, char **);
char		*cmd_interpret(t_data *, char *);
char            *disting_path(t_data *, t_file *, char *);
int		is_path(char *);

/*
** GET_BIN
*/
int		get_bin(t_data *);
int		get_file_dir(t_file **, char *);
char		*get_bin_dir(char **);
void		clean_bin(t_file *);

/*
** GET_ENV
*/
void		aff_env(t_env *);
int		get_env(t_data *, char **);
char		*get_env_val(char *);
char		*get_env_var(char *);

/*
** GET_GLOB
*/
t_file		*get_glob(char *, t_env *);
char		*get_full_path(char *, t_env *);
char		*get_latest_dir(char *);
void		free_glob(t_file *);

/*
** GET_HIS
*/
void		aff_his(t_his *);
int		add_cmd_to_his(t_data *, char *);
int		get_his(t_data *);
int		clear_his(t_data *);

/*
** MY_GETINPUT
*/
char		*get_input();

/*
** LIST_LINKER
*/
t_conf		*new_conf(t_conf *);
t_env		*new_env(t_env *);
t_file		*new_file(t_file *);
t_his		*new_his(t_his *);

/*
** MY_BASICS
*/
char		*my_strdup(char *);
void		my_putstr(char *);
int		my_strlen(char *);
void		my_putchar(char);

/*
** MY_STRCMP
*/
int		my_strcmp(char *, char *);
int		my_strcom(char *, char *);

/*
** SET_INIT
*/
int		set_init(t_data *, char **);

/*
** SET_STANDARD
*/
int		set_standard(t_data *);
int		insert_new_std(char *, char **, t_env *);

/*
** LIST_TO_TAB
*/
char		*concat_env(t_env *);
char		**list_to_tab(t_env *);
int		is_built_in(t_data *, char *);
int		call_built_in(t_data *, char **);

/*
** CMD_PARSER.C
*/
int		exe_all_cmd(t_data *);

/*
** CMD_PIPE.C
*/
int		cmd_pipe_multi(t_data *, t_conf *, int);
int		cmd_pipe(t_data *, t_conf *);

/*
** CMD_SIMPLE.C
*/
int		op_wait(t_data *);
int		op_xor(t_data *);
int		op_xor_wait(t_data *, char);

/*
** CMD_SIMPLE_EXE.C
*/
int		exe_cmd_fork(t_data *, t_conf *, char *);
int		exe_cmd_slash(t_data *, t_conf *);
int		exe_cmd(t_data *, t_conf *);

/*
** CMD_PIPE_EXE (ALL)
*/
int		exe_cmd_pipe(t_data *, t_conf *, int);
int		exe_cmd_in_dad(t_data *, t_conf *, char *, char **);
int		exe_cmd_in_son(t_data *, t_conf *, char *, char **);
int		exe_cmd_m1_dad(t_data *, t_conf *, char *, char **);
int		exe_cmd_m1_son(t_data *, t_conf *, char *, char **);
int		exe_cmd_m2_dad(t_data *, t_conf *, char *, char **);
int		exe_cmd_m2_son(t_data *, t_conf *, char *, char **);
int		exe_cmd_out1(t_data *, t_conf *, char *, char **);
int		exe_cmd_out1_s(t_data *, t_conf *, char *, char **);
int		exe_cmd_out2(t_data *, t_conf *, char *, char **);
int		exe_cmd_out2_s(t_data *, t_conf *, char *, char **);

/*
** CMD_PIPE_EXE_BUILT.C
*/
int		exe_cmd_in_built(t_data *, t_conf *, char *);
int		exe_cmd_multi1_built(t_data *, t_conf *, char *);
int		exe_cmd_multi2_built(t_data *, t_conf *, char *);
int		exe_cmd_out1_built(t_data *, t_conf *, char *);
int		exe_cmd_out2_built(t_data *, t_conf *, char *);

/*
** CMD_OPEN (ALL)
*/
int		open_input(t_conf *);
int		write_input_db(t_conf *, int, int);
int		open_input_db(t_conf *);
int		open_output(t_conf *);
int		open_erno(char *);
int		cmd_open_parser(t_conf *);

#endif
/* OEF */
