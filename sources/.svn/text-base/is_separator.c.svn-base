/*
** cmd_to_list.c for 42 in /home/thomps_j//FINAL
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 31 03:52:28 2013 julien thompson
** Last update Fri May 31 18:49:15 2013 julien thompson
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"shell.h"

int		is_separator(char *str)
{
  char		*tab[10];
  int		i;

  tab[0] = S_AND;
  tab[1] = S_WAIT;
  tab[2] = S_XOR;
  tab[3] = S_PIPE;
  tab[4] = S_BG;
  tab[5] = S_RDL;
  tab[6] = S_RSL;
  tab[7] = S_RDR;
  tab[8] = S_RSR;
  tab[9] = NULL;
  i = 0;
  while (tab[i] && !my_strcom(str, tab[i]))
    i++;
  if (tab[i])
    return (i);
  return (-1);
}
