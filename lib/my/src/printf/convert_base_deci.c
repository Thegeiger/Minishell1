/*
** convert_base.c for convert in /home/geiger_a/Bistromathique/convert_base
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Nov  1 13:59:01 2014 anthony geiger
** Last update Mon Jan  5 18:42:49 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

int		convert_base_deci_8_unint(unsigned int nb)
{
  int		base;
  unsigned int	res;
  unsigned int	*tab;
  int		i;

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
  my_rev_unint_tab(tab, i);
  free(tab);
  return (i);
}

int		convert_base_deci_16_un(unsigned int nb, char *str)
{
  int		base;
  unsigned int	res;
  char		*tab;
  unsigned int	i;

  tab = malloc(sizeof(*tab) * 16 + 1);
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

int	convert_base_deci_16(long nb, char *str)
{
  int   base;
  long   res;
  char	*tab;
  long   i;

  tab = malloc(sizeof(*tab) * 32 + 1);
  if (tab == NULL)
    return (1);
  res = 1;
  i = 0;
  base = 16;
  while (res != 0)
    {
      res = nb / base;
      tab[i] = str[nb % base];
      i++;
      nb = res;
    }
  tab[i] = '\0';
  i = my_rev_int_tab_long(tab, i);
  free(tab);
  return (i);
}
