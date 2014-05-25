/*
** cmd_parser.c for 42sh in /home/giraud_d//svn/42sh-2017-damian/link_dam/sources
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Fri May 31 21:58:40 2013 damien giraudet
** Last update Fri May 31 21:58:41 2013 damien giraudet
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<time.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"

int		exe_all_cmd(t_data *data)
{
  t_conf        *temp;
  int		res;

  temp = data->conf;
  while (temp)
    {
      data->statut.res = 0;
      if (temp->link != N_PIPE)
	{
	  if ((res = exe_cmd(data, temp)) < 0)
	    return (0);
	}
      else
	if ((res = cmd_pipe(data, temp)) < 0)
	  return (0);
      while (res-- > 0)
      	temp = temp->next;
      if (temp->link == N_WAIT || temp->link == N_XOR)
      	if (op_xor_wait(data, temp->link) == 1)
      	  return (0);
      temp = temp->next;
    }
  return (0);
}
