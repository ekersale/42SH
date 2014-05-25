/*
** get_bin.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 15 11:21:45 2013 julien thompson
** Last update Sun May 26 10:16:07 2013 elliot kersale
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"proto.h"
#include	"shell.h"
#include	"xerror.h"

void		clean_bin(t_file *bin)
{
  t_file	*temp;

  while (bin)
    {
      temp = bin;
      if (bin->name)
	free(bin->name);
      if (bin->path)
	free(bin->path);
      bin = bin->next;
      free(temp);
    }
  return ;
}

char		*get_bin_dir(char **str)
{
  int		i;
  int		j;
  char		*dir;

  i = 0;
  if (!**str)
    return (NULL);
  while (str[0][i] && str[0][i] != ':')
    i++;
  if (!(dir = malloc(sizeof(char) * (i + 2))))
    return (NULL);
  j = 0;
  while (j != i)
    dir[j++] = *str[0]++;
  dir[j++] = '/';
  dir[j] = 0;
  while (**str && **str != ':')
    str[0] += 1;
  str[0] += 1;
  return (dir);
}

int		get_file_dir(t_file **bin, char *path)
{
  DIR		*ptrdir;
  struct dirent	*entry;
  struct stat	sb;

  if (stat(path, &sb) == -1)
    return (SH_OK);
  if ((ptrdir = opendir(path)) == NULL)
    return (SH_OK);
  while ((entry = readdir(ptrdir)) != NULL)
    {
      if (!my_strcmp(entry->d_name, ".") && !my_strcmp(entry->d_name, ".."))
	{
	  if ((bin[0] = new_file(bin[0])) == NULL)
	    return (SH_FAIL);
	  if ((bin[0]->name = my_strdup(entry->d_name)) == NULL)
	    return (SH_FAIL);
	  if ((bin[0]->path = my_strdup(path)) == NULL)
	    return (SH_FAIL);
	  while (bin[0]->prev)
	    bin[0] = bin[0]->prev;
	}
    }
  closedir(ptrdir);
  free(entry);
  return (SH_OK);
}

int		get_bin(t_data *data)
{
  char		*path;
  char		*frag;

  path = data->std.path;
  data->bin = NULL;
  while ((frag = get_bin_dir(&path)))
    {
      if ((get_file_dir(&data->bin, frag)) == SH_FAIL)
      	return (SH_FAIL);
      free(frag);
    }
  return (SH_OK);
}
