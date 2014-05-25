/*
** error.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Tue May 14 23:48:33 2013 julien thompson
** Last update Fri May 31 22:05:27 2013 damien giraudet
*/

#include	<unistd.h>
#include	"error.h"

int		write_error(char c)
{
  if ((write(2, &c, 1)) == -1)
    return (0);
  return (1);
}

int		xerror(char *str)
{
  while (*str)
    if (!(write_error(*str++)))
      return (0);
  if (!(write_error('\n')))
    return (0);
  return (1);
}

int		my_xerror(char *str)
{
  while (*str)
    if (!(write_error(*str++)))
      return (-2);
  if (!(write_error('\n')))
    return (-2);
  return (-1);
}
