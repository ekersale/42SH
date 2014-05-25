/*
** pipe.c for 42sh in /home/giraud_d//42sh-2017-giraud_d/pre-rendu/parser
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Fri May 24 04:40:57 2013 damien giraudet
** Last update Fri May 31 22:47:17 2013 damien giraudet
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"proto.h"
#include	"shell.h"
#include	"types.h"
#include	"xerror.h"

int		exe_cmd_fork(t_data *data, t_conf *temp, char *exe)
{
  pid_t		pid;
  extern char	**environ;

  if ((pid = vfork()) < 0)
    return (my_xerror(ERR_FORK));
  if (pid == 0)
    {
      if ((temp->in_t > 0 || temp->out_t > 0) && cmd_open_parser(temp) < 0)
	if (kill(pid, 2) < 0)
	  return (my_xerror(ERR_KILL));
      if (execve(exe, temp->tab, environ) < 0)
	{
	  my_xerror(ERR_EXECVE);
	  if (kill(pid, 2) < 0)
	    return (my_xerror(ERR_KILL));
	}
    }
  else
    {
      if (waitpid(pid, &(data->statut.res), 0) < 0)
	return (my_xerror(ERR_WAITPID));
    }
  return (0);
}

int		exe_cmd_slash(t_data *data, t_conf *temp)
{
  char		*exe;

  if (access(temp->tab[0], F_OK) != 0)
    {
      data->statut.res = -1;
      write(2, temp->tab[0], strlen(temp->tab[0]));
      xerror(": Command not found");
      return (-1);
    }
  if (!(is_path(temp->tab[0])) || !(exe = my_strdup(temp->tab[0])))
    ;
  else
    {
      if (exe_cmd_fork(data, temp, exe) < 0)
	return (-1);
      free(exe);
    }
  return (0);
}

int		exe_cmd(t_data *data, t_conf *temp)
{
  t_file	*bin;
  char		*exe;

  if (is_built_in(data, temp->tab[0]) > -1)
    return (call_built_in(data, temp->tab));
  bin = data->bin;
  while (bin && !my_strcmp(temp->tab[0], bin->name))
    bin = bin->next;
  if (bin)
    {
      exe = cmb_str(bin->path, bin->name);
      if (exe_cmd_fork(data, temp, exe) < 0)
	return (my_xerror(ERR_EXECVE));
      free(exe);
    }
  else
    if (exe_cmd_slash(data, temp) < 0)
      return (-1);
  return (0);
}
