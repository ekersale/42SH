/*
** cmd_to_list.c for 42 in /home/thomps_j//FINAL
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 31 03:52:28 2013 julien thompson
** Last update Fri May 31 21:19:27 2013 julien thompson
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

char		*word_inhib(char *cmd, int *i, char inh)
{
  cmd += 1;
  while (*cmd && *cmd != inh)
    {
      cmd += 1;
      *i += 1;
    }
  if (*cmd)
    return (cmd);
  write(2, ERR_UNM, my_strlen(ERR_UNM));
  write_error(inh);
  xerror(".");
  return (NULL);
}

int		word_len(char *cmd)
{
  int		i;

  i = 0;
  while (*cmd && *cmd != ' ' && *cmd != '\t' && is_separator(cmd) == -1)
    {
      if (*cmd && (*cmd == '\'' || *cmd == '"'))
	{
	  if (!(cmd = word_inhib(cmd, &i, *cmd)))
	    return (-1);
	}
      else
	i++;
      cmd += 1;
    }
  return (i);
}

char		*concat_separ(char *cmd, t_his *stor)
{
  int		sep;

  if ((sep = is_separator(cmd)) == 1 || sep == 2 || sep == 5 || sep == 7)
    {
      if (!(stor->cmd = malloc(sizeof(char) * 3)))
	return (NULL);
      stor->cmd[0] = *cmd++;
      stor->cmd[1] = *cmd++;
      stor->cmd[2] = 0;
    }
  else
    {
      if (!(stor->cmd = malloc(sizeof(char) * 2)))
	return (NULL);
      stor->cmd[0] = *cmd++;
      stor->cmd[1] = 0;
    }
  return (cmd);
}

char		*concat_word(char *cmd, int len, t_his *stor)
{
  int		i;
  char		inh;

  i = 0;
  while (i != len)
    {
      if (*cmd == '\'' || *cmd == '"')
	{
	  inh = *cmd++;
	  while (*cmd != inh)
	    stor->cmd[i++] = *cmd++;
	  cmd += 1;
	}
      else
	stor->cmd[i++] = *cmd++;
    }
  stor->cmd[i] = 0;
  return (cmd);
}

t_his		*cmd_to_list(char *cmd)
{
  t_his		*stor;
  int		len;

  stor = NULL;
  skip_void(&cmd);
  while (*cmd && (len = word_len(cmd)) >= 0)
    {
      if (!(stor = new_his(stor)))
	return (NULL);
      if (is_separator(cmd) >= 0)
	cmd = concat_separ(cmd, stor);
      else
	{
	  if (!(stor->cmd = malloc(sizeof(char) * (len + 1))))
	    return (NULL);
	  cmd = concat_word(cmd, len, stor);
	}
      skip_void(&cmd);
      while (stor->prev)
	stor = stor->prev;
    }
  if (*cmd)
    return (NULL);
  return (stor);
}
