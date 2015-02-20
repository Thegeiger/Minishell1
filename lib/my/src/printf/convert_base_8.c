/*
** convert_base_deci_part3.c for part3 in /home/geiger_a/rendu/PSU_2014_my_printf/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 16:10:41 2014 anthony geiger
** Last update Mon Jan  5 18:43:26 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

void     my_rev_unint_tab(unsigned int *tab, int i)
{
  i--;
  while (i >= 0)
    {
      my_unputnbr(tab[i]);
      i--;
    }
}

void	my_rev_caract_nimpr(int *tab, int i)
{
  i--;
  my_putchar(92);
  if (i == 0)
    my_putstr("00");
  if (i == 1)
    my_putchar('0');
  while (i >= 0)
    {
      my_putchar(tab[i]);
      i--;
    }
}

int     my_nb_stack(char n)
{
  int   nb;

  nb = 0;
  nb = nb * 10 + n;
  return (nb);
}

int	convert_base_deci_2(int nb)
{
  int	base;
  int	res;
  int	*tab;
  int	i;

  if (nb < 0)
    nb = - nb;
  tab = malloc(sizeof(*tab) * 16 + 1);
  if (tab == NULL)
    return (1);
  res = 1;
  i = 0;
  base = 2;
  while (res != 0)
    {
      res = nb / base;
      tab[i] = nb % base;
      i++;
      nb = res;
    }
  my_rev_int_tab(tab, i);
  free(tab);
  return (i);
}

int     convert_base_deci_octal(char strnb, char *str)
{
  int   base;
  int   res;
  int  *tab;
  int   i;
  int	nb;

  tab = malloc(sizeof(*tab) * 16 + 1);
  if (tab == NULL)
    return (1);
  nb = strnb;
  res = 1;
  i = 0;
  base = my_strlen(str);
  while (res != 0)
    {
      res = nb / base;
      tab[i] = str[nb % base];
      i++;
      nb = res;
    }
  tab[i] = '\0';
  my_rev_caract_nimpr(tab, i);
  free(tab);
  return (i);
}
