/*
** list_linker.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Tue May 14 23:39:16 2013 julien thompson
** Last update Fri May 31 20:24:55 2013 julien thompson
*/

#include        <stdlib.h>
#include	"types.h"

t_his		*new_his(t_his *list)
{
  t_his		*temp;

  if (!(temp = malloc(sizeof(*temp))))
    return (NULL);
  if (list == NULL)
    {
      list = temp;
      list->next = NULL;
      list->prev = NULL;
      return (list);
    }
  while (list->next)
    list = list->next;
  temp->next = NULL;
  temp->prev = list;
  list->next = temp;
  return (temp);
}

t_file		*new_file(t_file *list)
{
  t_file	*temp;

  if (!(temp = malloc(sizeof(*temp))))
    return (NULL);
  if (list == NULL)
    {
      list = temp;
      list->next = NULL;
      list->prev = NULL;
      return (list);
    }
  while (list->next)
    list = list->next;
  temp->next = NULL;
  temp->prev = list;
  list->next = temp;
  return (temp);
}

t_env		*new_env(t_env *list)
{
  t_env		*temp;

  if (!(temp = malloc(sizeof(*temp))))
    return (NULL);
  if (list == NULL)
    {
      list = temp;
      list->next = NULL;
      list->prev = NULL;
      return (list);
    }
  while (list->next)
    list = list->next;
  temp->next = NULL;
  temp->prev = list;
  list->next = temp;
  return (temp);
}

t_conf		*new_conf(t_conf *list)
{
  t_conf	*temp;

  if (!(temp = malloc(sizeof(*temp))))
    return (NULL);
  temp->in_t = 0;
  temp->in_f = NULL;
  temp->out_t = 0;
  temp->out_f = NULL;
  if (list == NULL)
    {
      list = temp;
      list->next = NULL;
      list->prev = NULL;
      return (list);
    }
  while (list->next)
    list = list->next;
  temp->next = NULL;
  temp->prev = list;
  list->next = temp;
  return (temp);
}
