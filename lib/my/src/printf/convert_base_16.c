/*
** convert_base_deci_part2.c for part2 in /home/geiger_a/rendu/PSU_2014_my_printf/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 16:04:15 2014 anthony geiger
** Last update Mon Jan  5 18:43:18 2015 anthony geiger
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_rev_int_tab_long(char *tab, long i)
{
  int	r;

  i--;
  if (tab[i] == 48 && tab[i + 1] == '\0')
    {
      my_putstr("(nil)");
      return (5);
    }
  my_putstr("0x");
  r = 2;
  while (i >= 0)
    {
      my_putchar(tab[i]);
      i--;
      r++;
    }
  return (r);
}

void     my_rev_int_tab_un(char *tab, long i)
{
  i--;
  while (i >= 0)
    {
      my_putchar(tab[i]);
      i--;
    }
}

void     my_rev_int_tab(int *tab, int i)
{
  i--;
  while (i >= 0)
    {
      my_putnbr(tab[i]);
      i--;
    }
}
