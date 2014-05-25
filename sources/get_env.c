/*
** get_env.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 15 00:09:09 2013 julien thompson
** Last update Sun May 26 10:16:17 2013 elliot kersale
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"proto.h"

char		*get_env_var(char *str)
{
  int		i;
  int		j;
  char		*var;

  i = 0;
  while (str[i] && str[i] != '=')
    i++;
  if (!(var = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  j = -1;
  while (++j != i)
    var[j] = str[j];
  var[j] = 0;
  return (var);
}

char		*get_env_val(char *str)
{
  int		i;
  int		j;
  char		*val;

  i = 0;
  while (str[i] && str[i] != '=')
    i++;
  if (!(val = malloc(sizeof(char) * (my_strlen(str) - ++i + 1))))
    return (NULL);
  j = 0;
  while (str[i])
    val[j++] = str[i++];
  val[j] = 0;
  return (val);
}

int		get_env(t_data *data, char **env)
{
  t_env		*list;
  int		i;

  list = NULL;
  i = 0;
  while (env[i])
    {
      list = new_env(list);
      if (!(list->var = get_env_var(env[i])))
	return (1);
      if (!(list->val = get_env_val(env[i++])))
	return (1);
      while (list->prev)
	list = list->prev;
    }
  data->env = list;
  return (0);
}

void		aff_env(t_env *env)
{
  while (env)
    {
      my_putstr(env->var);
      my_putchar('=');
      my_putstr(env->val);
      my_putchar('\n');
      env = env->next;
    }
  return ;
}
