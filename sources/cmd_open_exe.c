/*
** cmd_open.c for 42sh in /home/giraud_d//svn/42sh-2017-damian/link_dam/sources
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Wed May 29 03:50:19 2013 damien giraudet
** Last update Mon Jun 24 16:44:14 2013 elliot kersale
*/

#include	<unistd.h>
#include        <stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include        <string.h>
#include	"proto.h"
#include	"types.h"
#include	"xerror.h"

int		open_input(t_conf *cmd)
{
  int		fd;

  if ((fd = open(cmd->in_f, O_RDONLY)) < 0)
    return (open_erno(cmd->in_f));
  if (dup2(fd, 0) < 0)
    return (my_xerror(ERR_DUP2));
  return (0);
}

int		write_input_db(t_conf *cmd, int fd, int nb)
{
  char		*buffer;
  unsigned int 	bcl;
  ssize_t	size;

  while (nb != 0)
    {
      if ((buffer = malloc(4096 * sizeof(char))) == NULL)
	return (my_xerror(ERR_MALLOC));
      write(1, "? ", 2);
      if ((size = read(0, buffer, 4095)) < 0)
	return (my_xerror(ERR_READ));
      buffer[size - 1] = 0;
      if ((nb = strcmp(buffer, cmd->in_f)) == 0)
	nb = 0;
      else
	{
	  bcl = 0;
	  while (bcl < strlen(buffer))
	    write(fd, &buffer[bcl++], 1);
	  write(fd, "\n", 1);
	}
    }
  return (0);
}

int		open_input_db(t_conf *cmd)
{
  int		fd;
  int		nb;

  if ((fd = open(".tmp", O_CREAT | O_TRUNC | O_RDWR,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (-1);
  nb = -1;
  if (write_input_db(cmd, fd, nb) < 0)
    return (-1);
  if (close(fd) < 0)
    return (my_xerror(ERR_CLOSE));
  if ((fd = open(".tmp", O_RDONLY)) == -1)
    return (-1);
  if (dup2(fd, 0) < 0)
    return (my_xerror(ERR_DUP2));
  return (0);
}

int		open_output(t_conf *cmd)
{
  int		fd;

  if (cmd->out_t == 1)
    {
      if ((fd = open(cmd->out_f, O_CREAT | O_WRONLY | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (open_erno(cmd->out_f));
    }
  else
    {
      if ((fd = open(cmd->out_f, O_WRONLY | O_APPEND | O_CREAT,
  		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (open_erno(cmd->out_f));
    }
  if (dup2(fd, 1) < 0)
    return (my_xerror(ERR_DUP2));
  return (0);
}
