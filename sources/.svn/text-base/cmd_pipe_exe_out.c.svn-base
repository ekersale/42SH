/*
** cmd_pipe_exe_out.c for 42sh in /home/giraud_d//final
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Sun May 26 19:11:37 2013 damien giraudet
** Last update Fri May 31 20:21:46 2013 damien giraudet
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"
#include	"xerror.h"

int		exe_cmd_out1(t_data *data, t_conf *cmd, char *exe, char **env)
{
  pid_t		pid;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if (exe_cmd_out1_s(data, cmd, exe, env) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror("Fatal Kill Error\n"));
    }
  else
    {
      if (close(data->statut.pipe1[0]) < 0)
	return (my_xerror(ERR_CLOSE));
      if (waitpid(pid, &(data->statut.res), 0) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_out1_s(t_data *data, t_conf *cmd, char *exe, char **env)
{
  if (cmd->out_t > 0 && cmd_open_parser(cmd) < 0)
    return (-1);
  if (dup2(data->statut.pipe1[0] , 0) < 0)
    return (my_xerror(ERR_DUP2));
  if (execve(exe, cmd->tab, env) < 0)
    return (my_xerror(ERR_EXECVE));
  return (-1);
}

int		exe_cmd_out2(t_data *data, t_conf *cmd, char *exe, char **env)
{
  pid_t		pid;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if (exe_cmd_out2_s(data, cmd, exe, env) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror("Fatal Kill Error\n"));
    }
  else
    {
      if (close(data->statut.pipe2[0]) < 0)
	return (my_xerror(ERR_CLOSE));
      if (waitpid(pid, &(data->statut.res), 0) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_out2_s(t_data *data, t_conf *cmd, char *exe, char **env)
{
  if ((cmd->in_t > 0 || cmd->out_t > 0) && cmd_open_parser(cmd) < 0)
    return (-1);
  if (dup2(data->statut.pipe2[0] , 0) < 0)
    return (my_xerror(ERR_DUP2));
  if (execve(exe, cmd->tab, env) < 0)
    return (my_xerror(ERR_EXECVE));
  return (0);
}
