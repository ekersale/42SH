/*
** my_getinput.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 08:07:06 2013 julien thompson
** Last update Tue May 28 18:52:11 2013 damien giraudet
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"proto.h"
#include	"my_getline.h"

char            *get_input()
{
  char          *buffer;
  int           i;

  if ((buffer = malloc(sizeof(char) * LIMIT + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i != LIMIT)
    buffer[i++] = 0;
  if ((i = read(0, buffer, LIMIT)) == 0)
    return (NULL);
  buffer[i] = 0;
  if (buffer[i - 1] == '\n')
    buffer[i - 1] = 0;
  return (buffer);
}
