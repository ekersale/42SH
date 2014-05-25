/*
** set_init.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 02:09:45 2013 julien thompson
** Last update Sun May 26 10:19:22 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"shell.h"
#include	"proto.h"

int		set_init(t_data *data, char **env)
{
  int		init;
  t_env		*tmp;

  init = 0;
  init += get_his(data);
  if ((init += get_env(data, env)) != SH_OK)
    return (SH_FAIL);
  tmp = data->env;
  while (tmp && !my_strcmp(tmp->var, PWD_VAR))
    tmp = tmp->next;
  if (!tmp || (data->std.pwd = my_strdup(tmp->val)) == NULL)
    return (SH_FAIL);
  data->std.old = NULL;
  data->std.home = NULL;
  data->std.path = NULL;
  data->std.host = NULL;
  data->conf = NULL;
  if (set_standard(data) == SH_FAIL)
    return (SH_FAIL);
  return (SH_OK);
}
