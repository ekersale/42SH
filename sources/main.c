/*
** main.c for 42 in /home/thomps_j//42-true
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Tue May 14 23:40:22 2013 julien thompson
** Last update Sun May 26 08:18:56 2013 julien thompson
*/

#include	<stdio.h>
#include	"shell.h"
#include	"types.h"
#include	"proto.h"
#include	"xerror.h"

int		main(int ac, char **av, char **env)
{
  t_data	data;

  (void)ac;
  (void)av;
  if (!(*env))
    {
      xerror(MISS_ENV);
      return (SH_FAIL);
    }
  if (set_init(&data, env) == SH_FAIL)
    {
      xerror(ERR_INIT);
      return (SH_FAIL);
    }
  get_bin(&data);
  data.status = SH_OK;
  if ((core(&data)) == SH_FAIL)
    return (1);
  return (0);
}
