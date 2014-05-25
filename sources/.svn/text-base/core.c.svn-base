/*
** core.c for 42 in /home/thomps_j//42-true/total/all
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 08:12:58 2013 julien thompson
** Last update Fri May 31 22:04:15 2013 damien giraudet
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

void		exec_manager(t_data *data)
{
  pid_t		pid;
  t_conf	*conf;

  conf = data->conf;
  while (data->status == SH_OK && conf)
    {
      data->status = 0;
      if (is_built_in(data, conf->tab[0]) >= 0)
	call_built_in(data, conf->tab);
      else
	if ((pid = fork()) == 0)
	  {
	    uni_executor(data, conf->tab);
	    data->status = 0;
	  }
      wait(0);
      conf = conf->next;
    }
  return ;
}

char		*prompt_and_input(t_data *data)
{
  aff_prompt(data);
  return (get_input());
}

int		core(t_data *data)
{
  char		*buf;

  while (data->status == SH_OK && (buf = prompt_and_input(data)))
    {
      if ((add_cmd_to_his(data, buf)) == SH_FAIL)
	return (xerror(ERR_MALLOC));
      if ((get_bin(data)) == SH_FAIL)
	return (xerror(ERR_MALLOC));
      if (cmd_translator(buf, data) == SH_OK)
	exe_all_cmd(data);
	/* if (exe_all_cmd(data) < 0) */
	/*   return (0); */
      clean_bin(data->bin);
      free(buf);
    }
  return (0);
}
