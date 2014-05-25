/*
** built_in.c for 42 in /home/thomps_j//SVN/temp/42sh-2017-giraud_d/F2
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun May 26 20:18:12 2013 julien thompson
** Last update Fri May 31 22:35:35 2013 damien giraudet
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"xerror.h"
#include	"proto.h"
#include	"shell.h"

static int (*tab[])(t_data *, char **) =
{
  &check_cd,
  &bt_exit,
  &bt_env,
  &bt_setenv,
  &bt_unsetenv,
  &bt_echo,
  &bt_history,
  &bt_alias,
  NULL
};

int		is_built_in(t_data *data, char *str)
{
  char		*istab[9];
  int		i;

  istab[0] = BT_CHDIR;
  istab[1] = BT_EXIT;
  istab[2] = BT_ENV;
  istab[3] = BT_SENV;
  istab[4] = BT_USENV;
  istab[5] = BT_ECHO;
  istab[6] = BT_HIS;
  istab[7] = BT_ALI;
  istab[8] = NULL;
  i = 0;
  while (istab[i] && !my_strcmp(str, istab[i]))
    i++;
  if (istab[i])
    {
      data->cur_bt = i;
      return (i);
    }
  data->cur_bt = -1;
  return (-1);
}

int		call_built_in(t_data *data, char **arg)
{
  int		bt;

  bt = data->cur_bt;
  if (bt >= 0 && bt <= 7)
    if ((tab[bt](data, arg)) == 1)
      return (SH_FAIL);
  return (SH_OK);
}
