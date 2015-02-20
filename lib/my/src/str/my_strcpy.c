/*
** my_strcpy.c for strcpy in /home/geiger_a/lib/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 19:43:14 2015 anthony geiger
** Last update Tue Jan  6 19:43:56 2015 Anthony Geiger
*/

#include "my.h"

char    *my_strcpy(char *dest, char *src)
{
  char  *dest_addr;

  dest_addr = dest;
  while ((*src) != '\0')
    {
      (*dest) = (*src);
      dest++;
      src++;
    }
  *dest = '\0';
  return (dest_addr);
}
