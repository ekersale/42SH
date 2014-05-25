/*
** cmd_pipe_exe.c for 42sh in /home/giraud_d//42sh-2017-giraud_d/pre-rendu/parser
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Sun May 26 02:49:06 2013 damien giraudet
** Last update Fri May 31 20:31:10 2013 damien giraudet
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<string.h>
#include	<stdlib.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"
#include	"xerror.h"

static int      (*g_cmd_pipe_ptr[5])(t_data *, t_conf *, char *, char **) =
{
  &exe_cmd_in_dad,
  &exe_cmd_m1_dad,
  &exe_cmd_m2_dad,
  &exe_cmd_out1,
  &exe_cmd_out2,
};

int		exe_cmd_pipe(t_data *data, t_conf *cmd, int i)
{
  t_file        *bin;
  char          *exe;
  extern char   **environ;

  bin = data->bin;
  while (bin && !my_strcmp(cmd->tab[0], bin->name))
    bin = bin->next;
  if (!bin)
    {
      data->statut.res = -1;
      write(2, cmd->tab[0], my_strlen(cmd->tab[0]));
      xerror(": Command not found");
    }
  else
    {
      exe = cmb_str(bin->path, bin->name);
      if ((g_cmd_pipe_ptr[i])(data, cmd, exe, environ) < 0)
	return (-1);
      free(exe);
    }
  return (0);
}

int		exe_cmd_in_dad(t_data *data, t_conf *cmd, char *exe, char **env)
{
  pid_t		pid;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if (exe_cmd_in_son(data, cmd, exe, env) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror(ERR_KILL));
    }
  else
    {
      if (close(data->statut.pipe1[1]) < 0)
      	return (my_xerror(ERR_CLOSE));
      if (waitpid(pid, &(data->statut.res), WNOHANG) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_in_son(t_data *data, t_conf *cmd, char *exe, char **env)
{
  if (cmd->in_t > 0 && cmd_open_parser(cmd) < 0)
    return (-1);
  if (close(data->statut.pipe1[0]) < 0)
    return (my_xerror(ERR_CLOSE));
  if (dup2(data->statut.pipe1[1] , 1) < 0)
    return (my_xerror(ERR_DUP2));
  if (execve(exe, cmd->tab, env) < 0)
    return (my_xerror(ERR_EXECVE));
  return (0);
}
