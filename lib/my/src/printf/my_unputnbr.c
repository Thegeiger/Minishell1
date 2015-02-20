/*
** my_put_nbr.c for my_put_nbr in /home/geiger_a/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Oct  7 09:44:23 2014 anthony geiger
** Last update Mon Jan  5 18:45:01 2015 anthony geiger
*/

#include "my.h"

int		my_unputnbr(unsigned int nb)
{
  unsigned int	div;
  int		i;

  i = 0;
  div = 1;
  while (div < 1000000000 && nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      if (div == 1)
	my_putchar(nb % 10 + 48);
      else
	my_putchar(nb / div + 48);
      i++;
      nb = nb % div;
      div = div / 10;
    }
  return (i);
}

int     my_unputnbrnoaffich(unsigned int nb)
{
  int   div;
  int   i;

  i = 0;
  div = 1;
  while (div < 1000000000 && nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      i++;
      nb = nb % div;
      div = div / 10;
    }
  return (i);
}

int     my_unputnbrs(unsigned int nb, int p, int nbr)
{
  int   i;
  int   ret;
  int   r;

  r = 0;
  ret = 0;
  if (p == 1)
    {
      i = my_unputnbrnoaffich(nb);
      while (nbr > i)
        {
          my_putchar('0');
          nbr--;
          r++;
        }
    }
  ret = r;
  r = my_unputnbr(nb);
  r = ret + r;
  return (r);
}

int		my_lputnbr(long int nb)
{
  long int	div;
  int		i;

  i = 0;
  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
      i++;
    }
  while (nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      if (div == 1)
	my_putchar(nb % 10 + 48);
      else
	my_putchar(nb / div + 48);
      i++;
      nb = nb % div;
      div = div / 10;
    }
  return (i);
}
