/*
** get_his.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 15 01:10:17 2013 julien thompson
** Last update Sun May 26 17:23:27 2013 julien thompson
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"shell.h"
#include	"proto.h"
#include	"my_getline.h"

int		get_his(t_data *data)
{
  t_his		*list;
  char		*line;
  int		fd;

  if ((fd = open(HIS_FILE, O_CREAT | O_APPEND | O_RDWR,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (1);
  list = NULL;
  while ((line = my_getline(fd)))
    {
      if (*line)
	{
	  list = new_his(list);
	  if (!(list->cmd = my_strdup(line)))
	    return (1);
	  while (list->prev)
	    list = list->prev;
	}
    }
  data->his = list;
  data->h_fd = fd;
  return (0);
}

int		add_cmd_to_his(t_data *data, char *cmd)
{
  char		*new;
  t_his		*temp;

  if (!(new = my_strdup(cmd)))
    return (SH_FAIL);
  temp = new_his(data->his);
  temp->cmd = new;
  if (write(data->h_fd, new, my_strlen(new)) == -1)
    return (SH_FAIL);
  if (write(data->h_fd, "\n", 1) == -1)
    return (SH_FAIL);
  return (SH_OK);
}

int		clear_his(t_data *data)
{
  t_his		*tmp;

  tmp = data->his;
  while (data->his)
    {
      free(data->his->cmd);
      tmp = data->his;
      data->his = data->his->next;
      free(tmp);
    }
  data->his = NULL;
  close(data->h_fd);
  data->h_fd = open(HIS_FILE, O_RDONLY | O_TRUNC);
  close(data->h_fd);
  if (get_his(data) == SH_FAIL)
    return (SH_FAIL);
  return (SH_OK);
}

void		aff_his(t_his *his)
{
  while (his)
    {
      printf("%s\n", his->cmd);
      his = his->next;
    }
  return ;
}
