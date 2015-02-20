/*
** my_strnscpy.c for my_strnscpy in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Wed Jan  7 02:05:46 2015 Anthony Geiger
** Last update Wed Jan  7 20:51:06 2015 Anthony Geiger
*/

#include "my.h"

char    *my_strnscpy(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  j = 0;
  i = nb;
  if (nb > my_strlen(src))
    return (NULL);
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
