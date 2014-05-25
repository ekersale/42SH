/*
** cmd_open_parser.c for 42sh in /home/giraud_d//svn/42sh-2017-damian/link_dam/sources
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Fri May 31 20:33:20 2013 damien giraudet
** Last update Fri May 31 20:36:45 2013 damien giraudet
*/

#include        <errno.h>
#include	<stdio.h>
#include	"proto.h"
#include	"types.h"
#include	"xerror.h"

int		open_erno(char *str)
{
  if (errno == EACCES)
    fprintf(stderr, "%s: Cannot access.\n", str);
  else
    if (errno == ENOENT)
      fprintf(stderr, "%s: No such file or directory.\n", str);
    else
      if (errno == ENOTDIR)
	fprintf(stderr, "%s: Is not a directory.\n", str);
      else
	my_xerror(ERR_OPEN);
  return (-1);
}

int		cmd_open_parser(t_conf *cmd)
{
  if (cmd->in_t == 1 && open_input(cmd) < 0)
    return (-1);
  else
    if (cmd->in_t == 2 && open_input_db(cmd) < 0)
      return (-1);
  if (cmd->out_t > 0 && open_output(cmd) < 0)
    return (-1);
  return (0);
}
