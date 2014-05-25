/*
** list_to_conf.c for 42 in /home/thomps_j//FINAL
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 31 17:28:54 2013 julien thompson
** Last update Fri May 31 20:53:58 2013 julien thompson
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

int		check_redir(t_his *stor)
{
  while (stor)
    {
      if (is_separator(stor->cmd) >= 5)
	if (!stor->next || is_separator(stor->next->cmd) != -1)
	  {
	    xerror(CMD_MISS);
	    return (0);
	  }
      stor = stor->next;
    }
  return (1);
}

int		check_cmd(t_conf *cmd)
{
  t_conf	*temp;

  temp = cmd;
  while (cmd)
    {
      if (!cmd->tab[0] && cmd->link > 0)
	{
	  xerror(CMD_NULL);
	  return (0);
	}
      cmd = cmd->next;
    }
  while (temp->next)
    temp = temp->next;
  if (temp->link > 0 && !temp->next) 
	{
	  xerror(CMD_NULL);
	  return (0);
	}
  return (1);
}
