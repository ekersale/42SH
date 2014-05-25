/*
** bt_env.c for 42 in /home/thomps_j//SVN/temp/42sh-2017-giraud_d/F2
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 21:12:54 2013 julien thompson
** Last update Fri May 31 22:45:17 2013 julien thompson
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

int		new_env_var(t_data *data, char *var, char *val)
{
  t_env		*env;

  env = data->env;
  env = new_env(env);
  if (!(env->var = my_strdup(var)))
    return (1);
  if (val)
    {
      if (!(env->val = my_strdup(val)))
	return (1);
    }
  else
    {
      if (!(env->val = my_strdup("")))
	return (1);
    }
  while (env->prev)
    env = env->prev;
  data->env = env;
  return (0);
}

void		ch_env_var(t_env *env, char *val)
{
  free(env->val);
  if (val)
    env->val = my_strdup(val);
  else
    env->val = my_strdup("");
}

int		bt_setenv(t_data *data, char **arg)
{
  int		i;
  t_env		*env;

  i = 0;
  while (arg[i])
    i++;
  if (i > 3)
    {
      xerror(ERR_SETV);
      return (1);
    }
  if (i == 1)
    {
      aff_env(data->env);
      return (0);
    }
  env = data->env;
  while (env && !my_strcmp(env->var, arg[1]))
    env = env->next;
  if (env)
    ch_env_var(env, arg[2]);
  else
    if (new_env_var(data, arg[1], arg[2]))
      return (1);
  return (0);
}
