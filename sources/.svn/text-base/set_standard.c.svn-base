/*
** set_standard.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sat May 25 18:25:13 2013 julien thompson
** Last update Sun May 26 10:19:35 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"xerror.h"
#include	"shell.h"
#include	"proto.h"

int		insert_new_std(char *ref, char **dest, t_env *env)
{
  while (env && !my_strcmp(ref, env->var))
    env = env->next;
  if (env)
    {
      if (dest[0])
	free(dest[0]);
      if ((dest[0] = my_strdup(env->val)) == NULL)
	{
	  xerror(ERR_MALLOC);
	  return (SH_FAIL);
	}
    }
  return (SH_OK);
}

int		set_standard(t_data *data)
{
  int		ret;

  ret = 0;
  if (data->std.pwd)
    {
      if (data->std.old)
	free(data->std.old);
      if (!(data->std.old = my_strdup(data->std.pwd)))
	return (SH_FAIL);
    }
  ret += insert_new_std(PWD_VAR, &data->std.pwd, data->env);
  ret += insert_new_std(PATH_VAR, &data->std.path, data->env);
  ret += insert_new_std(HOME_VAR, &data->std.home, data->env);
  ret += insert_new_std(HOST_VAR, &data->std.host, data->env);
  if (ret != SH_OK)
    return (SH_FAIL);
  return (SH_OK);
}
