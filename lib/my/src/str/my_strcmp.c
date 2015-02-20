/*
** my_getnbr.c for my_get_nbr in /home/geiger_a/lib/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 19:10:14 2015 anthony geiger
** Last update Tue Jan  6 18:24:37 2015 Anthony Geiger
*/

#include "my.h"

int     my_strcmp(char *a, char *b)
{
  while (((*a) != '\0' && (*b) != '\0'))
    {
      if (*(a) == *(b))
        {
          a++;
          b++;
        }
      else
        break ;
    }
  return ((int) ((*a) - (*b)));
}
