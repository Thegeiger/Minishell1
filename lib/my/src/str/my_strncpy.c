/*
** my_strncpy.c<2> for my_strncpy in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 19:38:18 2015 Anthony Geiger
** Last update Wed Jan  7 02:11:44 2015 Anthony Geiger
*/

#include "my.h"

char    *my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i != nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
