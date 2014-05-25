/*
** my_basics.c for std in /home/thomps_j//gnl_salut
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sat May 11 21:23:19 2013 julien thompson
** Last update Fri May 31 04:37:05 2013 julien thompson
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"proto.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*my_strdup(char *str)
{
  char		*new;
  int		i;

  if (!(new = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  i = -1;
  while (str[++i])
    new[i] = str[i];
  new[i] = 0;
  return (new);
}
