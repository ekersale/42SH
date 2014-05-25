/*
** bt_env.c for 42 in /home/thomps_j//SVN/temp/42sh-2017-giraud_d/F2
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 21:12:54 2013 julien thompson
** Last update Fri May 31 23:32:20 2013 vincent thibaud
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

void		aff_his_num(t_his *his)
{
  int		i;

  if (!his)
    return ;
  while (his->prev)
    his = his->prev;
  i = 0;
  while (his)
    {
      printf(HIS_AFF, i++, his->cmd);
      his = his->next;
    }
}

int		bt_history(t_data *data, char **arg)
{
  int		i;

  i = 0;
  while (arg[i])
    i++;
  if (i > 2)
    {
      xerror(ERR_HIS_TM);
      return (1);
    }
  if (i == 1)
    {
      aff_his_num(data->his);
      return (0);
    }
  return (0);
}
