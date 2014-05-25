/*
** my_getline.c for std in /home/thomps_j//gnl_salut
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri May 10 14:02:32 2013 julien thompson
** Last update Sun May 26 17:21:23 2013 julien thompson
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my_getline.h"
#include	"proto.h"

char		*cmb_str(char *src, char *add)
{
  char		*cmb;
  int		i;
  int		j;

  if (!(cmb = malloc(sizeof(char) * (my_strlen(src) + my_strlen(add) + 1))))
    return (NULL);
  i = -1;
  while (src[++i])
    cmb[i] = src[i];
  j = -1;
  while (add[++j])
    cmb[i++] = add[j];
  cmb[i] = 0;
  return (cmb);
}

char		*get_file_data(const int fd)
{
  char		buffer[LIMIT + 1];
  char		*temp;
  char		*str;
  int		ret;

  if (!(str = malloc(sizeof(char))))
    return (NULL);
  *str = 0;
  while ((ret = read(fd, buffer, LIMIT)) > 0)
    {
      buffer[ret] = 0;
      temp = cmb_str(str, buffer);
      free(str);
      str = temp;
    }
  if (ret == -1)
    return (NULL);
  return (str);
}

int		check_fd(char **save, int *turn, const int fd)
{
  if (fd == -1)
    {
      free(save[0]);
      save[0][0] = 0;
      *turn = 0;
      return (0);
    }
  if (!(*turn))
    if (!(*save = get_file_data(fd)))
      return (0);
  if (save[0][*turn] == '\n')
    *turn += 1;
  else
    if (save[0][*turn] == '\0')
      return (0);
  return (1);
}

char		*my_getline(const int fd)
{
  static char	*save = NULL;
  static int	turn = 0;
  char		*str;
  int		i;

  if (!(check_fd(&save, &turn, fd)))
    return (NULL);
  i = 0;
  while (save[turn++] && save[turn] != '\n')
    i++;
  if (!(str = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  turn -= i + 1;
  i = 0;
  while (save[turn] && save[turn] != '\n')
    str[i++] = save[turn++];
  str[i] = 0;
 return (str);
}
