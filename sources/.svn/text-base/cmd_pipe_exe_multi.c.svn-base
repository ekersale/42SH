/*
** cmd_pipe_exe_multi.c for 42sh in /home/giraud_d//final
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Sun May 26 19:10:00 2013 damien giraudet
** Last update Fri May 31 20:14:22 2013 damien giraudet
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"
#include	"xerror.h"

int		exe_cmd_m1_dad(t_data *data, t_conf *cmd, char *exe, char **env)
{
  pid_t		pid;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if (exe_cmd_m1_son(data, cmd, exe, env) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror(ERR_KILL));
    }
  else
    {
      if (close(data->statut.pipe2[0]) < 0)
      	return (my_xerror(ERR_CLOSE));
      if (close(data->statut.pipe1[1]) < 0)
      	return (my_xerror(ERR_CLOSE));
      if (waitpid(pid, &(data->statut.res), WNOHANG) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_m1_son(t_data *data, t_conf *cmd, char *exe, char **env)
{
  if (dup2(data->statut.pipe2[0] , 0) < 0)
    return (my_xerror(ERR_DUP2));
  if (close(data->statut.pipe1[0]) < 0)
    return (my_xerror(ERR_CLOSE));
  if (dup2(data->statut.pipe1[1] , 1) < 0)
    return (my_xerror(ERR_DUP2));
  if (execve(exe, cmd->tab, env) < 0)
    return (my_xerror(ERR_EXECVE));
  return (0);
}

int		exe_cmd_m2_dad(t_data *data, t_conf *cmd, char *exe, char **env)
{
  pid_t		pid;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if (exe_cmd_m2_son(data, cmd, exe, env) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror(ERR_KILL));
    }
  else
    {
      if (close(data->statut.pipe1[0]) < 0)
      	return (my_xerror(ERR_CLOSE));
      if (close(data->statut.pipe2[1]) < 0)
      	return (my_xerror(ERR_CLOSE));
      if (waitpid(pid, &(data->statut.res), WNOHANG) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_m2_son(t_data *data, t_conf *cmd, char *exe, char **env)
{
  if (dup2(data->statut.pipe1[0] , 0) < 0)
    return (my_xerror(ERR_DUP2));
  if (close(data->statut.pipe2[0]) < 0)
    return (my_xerror(ERR_CLOSE));
  if (dup2(data->statut.pipe2[1] , 1) < 0)
    return (my_xerror(ERR_DUP2));
  if (execve(exe, cmd->tab, env) < 0)
    return (my_xerror(ERR_EXECVE));
  return (0);
}
