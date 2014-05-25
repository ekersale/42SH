/*
** my_cd.c for my_cd in /home/kersal_e//local/42sh
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Sun May 26 01:52:26 2013 elliot kersale
** Last update Fri May 31 23:49:54 2013 elliot kersale
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	"proto.h"
#include	"types.h"

void		gere_erno(char *str)
{
  if (errno == EACCES)
    fprintf(stderr, "%s: Cannot access.\n", str);
  else
    if (errno == ENOENT)
      fprintf(stderr, "%s: No such file or directory.\n", str);
    else
      if (errno == EBADF)
	fprintf(stderr, "%s: Invalid path name.\n", str);
      else
	if (errno == ENOTDIR)
	  fprintf(stderr, "%s: Is not a directory.\n", str);
  return ;
}

int		move_home(t_data *data, char **cmd)
{
  char		*arg[4];

  arg[0] = "setenv";
  data->std.old = data->std.pwd;
  data->std.pwd = data->std.home;
  arg[1] = "PWD";
  arg[2] = data->std.pwd;
  arg[3] = NULL;
  /* arg[1] = data->std.pwd; */
  /* arg[2] = NULL; */
  if ((chdir(data->std.pwd)) == -1)
    {
      gere_erno(cmd[1]);
      data->statut.res = -1;
      return (-1);
    }
  bt_setenv(data, arg);
  return (0);
}

int		move_before(t_data *data, char **cmd)
{
  char		*tmp;
  char		*arg[4];

  arg[0] = "setenv";
  tmp = data->std.pwd;
  if ((chdir(data->std.old)) == -1)
    {
      gere_erno(cmd[1]);
      data->statut.res = -1;
      return (-1);
    }
  data->std.pwd = data->std.old;
  data->std.old = tmp;
  arg[1] = "PWD";
  arg[2] = data->std.pwd;
  arg[3] = NULL;
  bt_setenv(data, arg);
  return (0);
}

int		move_way(t_data *data, char **cmd)
{
  char		*arg[4];

  arg[0] = "setenv";
  if ((chdir(cmd[1])) == -1)
    {
      gere_erno(cmd[1]);
      data->statut.res = -1;
      return (-1);
    }
  data->std.old = data->std.pwd;
  data->std.pwd = cmd[1];
  arg[1] = "PWD";
  arg[2] = data->std.pwd;
  arg[3] = NULL;
  bt_setenv(data, arg);
  return (0);
}

int		check_cd(t_data *data, char **cmd)
{
  if (cmd[1] == NULL || (strcmp(cmd[1], "~")) == 0)
    return (move_home(data, cmd));
  else
    if ((strcmp(cmd[1], "-")) == 0)
      return (move_before(data, cmd));
    else
      return (move_way(data, cmd));
}
