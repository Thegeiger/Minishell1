/*
** my_strnsdup.c for my_strnsdup.c in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Wed Jan  7 02:03:37 2015 Anthony Geiger
** Last update Wed Jan  7 02:11:44 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"

char    *my_strnsdup(char *src, int nb)
{
  char  *new_str;
  int   size;

  size = my_strlen(src);
  new_str = malloc(sizeof(char) * size + 1);
  if (new_str == 0)
    return (0);
  my_strnscpy(new_str, src, nb);
  return (new_str);
}
