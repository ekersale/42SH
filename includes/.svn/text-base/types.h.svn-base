/*
** types.h for test in /home/thomps_j//SVN/42sh-2017-giraud_d/exe_cmd/new
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu May  9 17:50:22 2013 julien thompson
** Last update Fri May 31 23:27:26 2013 vincent thibaud
*/

#ifndef		_TYPES_H__
# define	_TYPES_H__

typedef struct	s_file
{
  char		*name;
  char		*path;
  struct s_file	*prev;
  struct s_file	*next;
}		t_file;

typedef struct	s_conf
{
  char		**tab;
  char		link;
  char		in_t;
  char		out_t;
  char		*in_f;
  char		*out_f;
  struct s_conf	*prev;
  struct s_conf	*next;
}		t_conf;

typedef struct  s_cmd
{
  int		pipe1[2];
  int		pipe2[2];
  int		fdin;
  int		fdout;
  int		res;
}		t_cmd;

typedef struct	s_env
{
  char		*var;
  char		*val;
  struct s_env	*prev;
  struct s_env	*next;
}		t_env;

typedef struct	s_his
{
  char		*cmd;
  struct s_his	*prev;
  struct s_his	*next;
}		t_his;

typedef struct	s_std
{
  char		*host;
  char		*home;
  char		*path;
  char		*pwd;
  char		*old;
}		t_std;

typedef struct	s_data
{
  int		status;
  int		std_in;
  int		std_out;
  int		cur_bt;
  int		p_len;
  int		h_fd;
  int		a_fd;
  t_std		std;
  t_env		*env;
  t_file	*bin;
  t_conf	*conf;
  t_cmd		statut;
  t_file	*glob;
  t_his		*his;
  t_env		*alias;
  char		*line;
  char		**sep;
}		t_data;

t_file		*new_file(t_file *);
t_conf		*new_conf(t_conf *);
t_env		*new_env(t_env *);
t_his		*new_his(t_his *);

#endif
