/*
** bt_env.c for 42 in /home/thomps_j//SVN/temp/42sh-2017-giraud_d/F2
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 21:12:54 2013 julien thompson
** Last update Fri May 31 22:02:04 2013 julien thompson
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

void		remove_env_var(t_data *data, char *var)
{
  t_env		*env;

  env = data->env;
  while (env && !my_strcmp(env->var, var))
    env = env->next;
  if (!env)
    return ;
  if (!env->prev && !env->next)
    data->env = NULL;
  if (env->prev)
    env->prev->next = env->next;
  if (env->next)
    env->next->prev = env->prev;
  free(env->var);
  if (env->val)
    free(env->val);
  free(env);
  return ;
}

int		bt_unsetenv(t_data *data, char **arg)
{
  int		i;
  int		j;

  i = 0;
  while (arg[i])
    i++;
  if (i == 1)
    {
      xerror(ERR_UNSV);
      return (1);
    }
  j = 1;
  while (j != i)
    remove_env_var(data, arg[j++]);
  return (0);
}
