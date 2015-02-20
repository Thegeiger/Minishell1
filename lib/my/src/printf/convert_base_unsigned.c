/*
** convert_base_deci_part4.c for part4 in /home/geiger_a/PSU_2014_my_printf
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 16 10:55:42 2014 anthony geiger
** Last update Mon Jan  5 18:43:34 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

int			convert_base_deci_16_lun(long unsigned int nb, char *str)
{
  int			base;
  long unsigned int	res;
  char			*tab;
  unsigned int		i;

  tab = malloc(sizeof(*tab) * 20 + 1);
  if (tab == NULL)
    return (1);
  res = 1;
  i = 0;
  base = 16;
  while (res != 0)
    {
      res = nb / base;
      tab[i] = nb % base;
      tab[i] = str[nb % base];
      i++;
      nb = res;
    }
  tab[i] = '\0';
  my_rev_int_tab_un(tab, i);
  free(tab);
  return (i);
}

void     my_rev_lunint_tab(long unsigned int *tab, int i)
{
  i--;
  while (i >= 0)
    {
      my_lunputnbr(tab[i]);
      i--;
    }
}

int			convert_base_deci_8_lunint(long unsigned int nb)
{
  int			base;
  long unsigned int	res;
  long unsigned int	*tab;
  int			i;

  tab = malloc(sizeof(*tab) * 16 + 1);
  if (tab == NULL)
    return (1);
  res = 1;
  i = 0;
  base = 8;
  while (res != 0)
    {
      res = nb / base;
      tab[i] = nb % base;
      i++;
      nb = res;
    }
  tab[i] = '\0';
  my_rev_lunint_tab(tab, i);
  free(tab);
  return (i);
}
