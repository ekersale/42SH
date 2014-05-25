/*
** executor.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 09:05:24 2013 julien thompson
** Last update Fri May 31 23:35:28 2013 vincent thibaud
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"xerror.h"
#include	"shell.h"
#include	"proto.h"
#include	"my_getline.h"

int		is_path(char *file)
{
  int		i;
  char		c;

  c = file[my_strlen(file) - 1];
  if (c == '/' || c == '.')
    return (0);
  if ((file[0] == '.' && file[1] == '.' && file[2] == '/') ||
      (file[0] == '.' && file[1] == '/') || *file == '/')
    return (1);
  i = 0;
  while (file[i] && file[i] != '/')
    i++;
  if (file[i] == '/')
    return (1);
  return (0);
}

char		*disting_path(t_data *data, t_file *bin, char *arg)
{
  char		*exe;

  if (bin)
    {
      if (!(exe = cmb_str(bin->path, bin->name)))
	return (NULL);
    }
  else
    {
      if (access(arg, F_OK) != 0)
	return (NULL);
      if (!(is_path(arg)) || !(exe = my_strdup(arg)))
	{
	  data->status = -1;
	  return (NULL);
	}
    }
  return (exe);
}

char		*cmd_interpret(t_data *data, char *arg)
{
  t_file	*bin;
  char		*exe;

  bin = data->bin;
  while (bin && !my_strcmp(arg, bin->name))
    bin = bin->next;
  if (!(exe = disting_path(data, bin, arg)))
    return (NULL);
  if (access(exe, X_OK) != 0)
    {
      free(exe);
      data->status = -1;
      return (NULL);
    }
  return (exe);
}

int		uni_executor(t_data *data, char **arg)
{
  char		*exe;
  char		**env;

  data->status = 1;
  if ((exe = cmd_interpret(data, arg[0])) == NULL)
    {
      if (data->status == 1)
	fprintf(stderr, "%s%s\n", arg[0], ERR_CMD);
      else
	fprintf(stderr, "%s%s\n", arg[0], ERR_PERM);
    }
  else
    {
      if (!(env = list_to_tab(data->env)))
	return (SH_FAIL);
      execve(exe, arg, env);
      fprintf(stderr, "%s%s\n", arg[0], ERR_CMD);
      free(exe);
    }
  return (SH_FAIL);
}
