/*
** exe_pipe.c for 42sh in /home/giraud_d//42sh-2017-giraud_d/pre-rendu/parser
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Sat May 25 18:18:21 2013 damien giraudet
** Last update Fri May 31 21:52:44 2013 damien giraudet
*/

#include	<unistd.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"
#include	"xerror.h"

int		cmd_pipe_multi(t_data *data, t_conf *cmd, int i)
{
  if (i % 2 == 1)
    {
      if (pipe(data->statut.pipe2) < 0)
	return (my_xerror(ERR_PIPE));
      if (exe_cmd_pipe(data, cmd, 2) < 0)
	return (-1);
    }
  else
    {
      if (pipe(data->statut.pipe1) < 0)
	return (my_xerror(ERR_PIPE));
      if (exe_cmd_pipe(data, cmd, 1) < 0)
	return (-1);
    }
  return (0);
}

int		cmd_pipe(t_data *data, t_conf *cmd)
{
  int		i;

  i = 1;
  if (pipe(data->statut.pipe1) < 0)
    return (my_xerror(ERR_PIPE));
  if (exe_cmd_pipe(data, cmd, 0) < 0)
    return (-1);
  cmd = cmd->next;
  while (cmd->link == N_PIPE)
    {
      if (cmd_pipe_multi(data, cmd, i) < 0)
	return (-1);
      i++;
      cmd = cmd->next;
    }
  if (i % 2 == 1)
    {
      if (exe_cmd_pipe(data, cmd, 3) < 0)
	return (-1);
    }
  else
    if (exe_cmd_pipe(data, cmd, 4) < 0)
      return (-1);
  return (i);
}
