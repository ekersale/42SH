/*
** list_to_conf.c for 42 in /home/thomps_j//FINAL
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 31 17:28:54 2013 julien thompson
** Last update Fri May 31 21:22:36 2013 julien thompson
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

int		words_to_separ(t_his *stor)
{
  int		i;
  int		sep;

  i = 0;
  while (stor && (sep = (is_separator(stor->cmd)) < 0 || sep > 4))
    {
      if (sep >= 5)
	  stor = stor->next->next;
      else
	{
	  stor = stor->next;
	  i++;
	}
    }
  return (i);
}

int		concat_redir(t_his **stor, t_conf *list, int sep)
{
  stor[0] = stor[0]->next;
  if (sep == 5 || sep == 6)
    {
      if (list->in_t)
	return (0);
      list->in_f = my_strdup(stor[0]->cmd);
      if (sep == 5)
	list->in_t = 2;
      else
	list->in_t = 1;
    }
  else
    {
      if (list->out_t)
	return (0);
      list->out_f = my_strdup(stor[0]->cmd);
      if (sep == 7)
	list->out_t = 2;
      else
	list->out_t = 1;
    }
  return (1);
}

void		set_link(t_his **stor, t_conf *list, int sep)
{
  if (!stor[0] || sep == N_AND || sep == N_BG)
    list->link = 0;
  else
    list->link = sep;
  if (stor[0])
    stor[0] = stor[0]->next;
}

t_his		*concat_list(t_his *stor, t_conf *list)
{
  int		i;
  int		sep;

  i = 0;
  while (stor && ((sep = is_separator(stor->cmd)) < 0 || sep > 4))
    {
      if (sep > 4)
	{
	  if (!(concat_redir(&stor, list, sep)))
	    {
	      xerror(CMD_AMB);
	      return (NULL);
	    }
	}
      else
	{
	  list->tab[i++] = my_strdup(stor->cmd);
	  stor = stor->next;
	}
    }
  set_link(&stor, list, sep);
  list->tab[i] = 0;
  return (stor);
}

int		list_to_conf(t_data *data, t_his *stor)
{
  t_conf	*list;
  int		words;

  list = NULL;
  while (stor)
    {
      list = new_conf(list);
      if (!(words = words_to_separ(stor)) && list->prev->link > 0)
	{
	  xerror(CMD_NULL);
	  return (0);
	}
      if (!(list->tab = malloc(sizeof(char *) * (words + 1))))
        return (0);
      stor = concat_list(stor, list);
      while (list->prev)
	list = list->prev;
    }
  data->conf = list;
  return (1);
}
