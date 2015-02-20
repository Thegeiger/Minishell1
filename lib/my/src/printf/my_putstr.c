/*
** my_putstr.c for putstr in /home/geiger_a/Bistromathique
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Oct 27 10:30:41 2014 anthony geiger
** Last update Tue Jan  6 18:47:37 2015 Anthony Geiger
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}
