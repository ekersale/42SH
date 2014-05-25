/*
** get_glob.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 15 01:54:09 2013 julien thompson
** Last update Sun May 26 10:15:56 2013 elliot kersale
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_getline.h"
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

void		free_glob(t_file *file)
{
  t_file	*temp;

  while (file)
    {
      temp = file;
      file = file->next;
      free(temp->path);
      free(temp->name);
      free(temp);
    }
  return ;
}

char		*get_latest_dir(char *str)
{
  char		*dir;
  int		i;
  int		j;
  int		n;

  i = my_strlen(str);
  while (i >= 0 && str[i] != '/' && str[i] != ' ' && str[i] != '\t')
    i--;
  j = i;
  while (j >= 0 && str[j] != ' ' && str[j] != '\t')
    j--;
  if (!(dir = malloc(sizeof(char) * (i - ++j + 2))))
    return (NULL);
  n = 0;
  while (j <= i)
    dir[n++] = str[j++];
  dir[n] = 0;
  return (dir);
}

char		*get_full_path(char *str, t_env *env)
{
  char		*dir;
  char		*temp;

  if (!(dir = get_latest_dir(str)))
    return (NULL);
  if (*dir != '/')
    {
      while (env && !my_strcmp(env->var, PWD_VAR))
	env = env->next;
      if (!env)
	{
	  xerror(MISS_PWD);
	  return (NULL);
	}
      temp = cmb_str("/", dir);
      free(dir);
      dir = cmb_str(env->val, temp);
      free(temp);
    }
  return (dir);
}

t_file		*get_glob(char *str, t_env *env)
{
  t_file	*glob;
  char		*dir;

  glob = NULL;
  if (!(dir = get_full_path(str, env)))
    return (NULL);
  return (glob);
}
