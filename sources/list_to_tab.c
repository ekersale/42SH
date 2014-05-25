/*
** list_to_tab.c for 42	 in /home/thomps_j//final
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 14:45:41 2013 julien thompson
** Last update Sun May 26 15:16:08 2013 julien thompson
*/

#include	<stdlib.h>
#include	<string.h>
#include	"xerror.h"
#include	"my_getline.h"
#include	"proto.h"

char		*concat_env(t_env *env)
{
  char		*str;

  if (!(str = strcat(env->var, "=")))
    return (NULL);
  if (!(str = cmb_str(str, env->val)))
    return (NULL);
  return (str);
}

char		**list_to_tab(t_env *env)
{
  char		**tab;
  t_env		*tmp;
  int		i;

  i = 0;
  tmp = env;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  if (!(tab = malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  i = 0;
  tmp = env;
  while (tmp)
    {
      if ((tab[i++] = concat_env(tmp)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}
