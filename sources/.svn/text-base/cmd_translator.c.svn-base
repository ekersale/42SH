/*
** cmd_translator.c for 42 in /home/thomps_j//FINAL
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 31 20:37:07 2013 julien thompson
** Last update Fri May 31 20:49:42 2013 julien thompson
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

int		cmd_translator(char *cmd, t_data *data)
{
  t_his		*stor;

  data->conf = NULL;
  if (!(stor = cmd_to_list(cmd)))
    return (SH_FAIL);
  if (!check_redir(stor))
    return (SH_FAIL);
  if (!(list_to_conf(data, stor)))
    return (SH_FAIL);
  if (!check_cmd(data->conf))
    return (SH_FAIL);
  return (SH_OK);
}
