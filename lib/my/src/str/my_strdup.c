/*
** my_strdup.c for strdup in /home/geiger_a/lib/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 19:51:23 2015 anthony geiger
** Last update Wed Jan  7 02:05:12 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"

char    *my_strdup(char *src)
{
  char  *new_str;
  int   size;

  size = my_strlen(src);
  new_str = malloc(sizeof(char) * size + 1);
  if (new_str == 0)
    return (0);
  my_strcpy(new_str, src);
  return (new_str);
}
