/*
** skip_func.c for 42 in /home/thomps_j//42-true/parser
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Wed May 22 14:23:54 2013 julien thompson
** Last update Fri May 31 16:32:17 2013 julien thompson
*/

#include	<stdio.h>
#include	"proto.h"

void		skip_void(char **str)
{
  while (**str && (**str == ' ' || **str == '\t'))
    *str += 1;
  return ;
}

void		skip_text(char **str)
{
  while (**str && **str != ' ' && **str != '\t')
    *str += 1;
  return ;
}

void		skip_word(char **str)
{
  while (**str && **str != ' ' && **str != '\t' && is_separator(*str) == -1)
    *str += 1;
  return ;
}
