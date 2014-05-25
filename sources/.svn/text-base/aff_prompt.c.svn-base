/*
** aff_prompt.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 02:36:31 2013 julien thompson
** Last update Fri May 31 22:51:53 2013 damien giraudet
*/

#include	<signal.h>
#include	<stdio.h>
#include	"proto.h"
#include	"shell.h"
#include	"xerror.h"

void		get_sigint(int sig)
{
  if (sig == 2)
    return ;
  if (sig == 11)
    {
      fprintf(stderr, "Segmentation Fault\n");
      fflush(stderr);
      return ;
    }
}

void		aff_small_pwd(char *pwd)
{
  int		i;
  int		slash;

  slash = 0;
  i = my_strlen(pwd);
  while (i != 0 && slash != 2)
    {
      if (pwd[i] == '/')
	slash++;
      i--;
    }
  printf(pwd + i + 1);
  return ;
}

void		aff_prompt(t_data *data)
{
  data->status = 0;
  printf(PRMT_IN);
  signal(SIGINT, get_sigint);
  if (!data->std.host || !data->std.pwd)
    printf("$>%s", PRMT_OUT);
  else
    {
      printf("%s:", data->std.host);
      aff_small_pwd(data->std.pwd);
      printf(" # %s", PRMT_OUT);
    }
  fflush(stdout);
}
