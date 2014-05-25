/*
** cmd_part1.c for 42sh in /home/giraud_d//42sh-2017-giraud_d/pre-rendu/parser
** 
** Made by damien giraudet
** Login   <giraud_d@epitech.net>
** 
** Started on  Sat May 25 17:42:50 2013 damien giraudet
** Last update Fri May 31 21:53:46 2013 damien giraudet
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	"proto.h"
#include	"types.h"
#include	"shell.h"

int		op_wait(t_data *data)
{
  if (data->statut.res == -1)
    return (1);
  if (!(WIFEXITED(data->statut.res)))
    return (1);
  return (0);
}

int		op_xor(t_data *data)
{
  if (data->statut.res != -1)
    return (1);
  if (WIFEXITED(data->statut.res))
    return (1);
  return (0);
}

int		op_xor_wait(t_data *data, char is)
{
  if (is == N_WAIT)
    return (op_wait(data));
  else
    return (op_xor(data));
}
