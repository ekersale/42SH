/*
** bt_env.c for 42 in /home/thomps_j//SVN/temp/42sh-2017-giraud_d/F2
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 21:12:54 2013 julien thompson
** Last update Fri May 31 23:31:46 2013 vincent thibaud
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"shell.h"

int		bt_echo(t_data *data, char **arg)
{
  int		i;
  int		j;

  (void)data;
  i = 1;
  j = 0;
  while (arg[j])
    j++;
  while (i != j)
    {
      if (i != 1)
	my_putstr(" ");
      my_putstr(arg[i++]);
    }
  my_putstr("\n");
  return (0);
}
