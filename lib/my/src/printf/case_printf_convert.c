/*
** case_printf_part3.c for case3 in /home/geiger_a/rendu/PSU_2014_my_printf/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 13:46:43 2014 anthony geiger
** Last update Mon Jan  5 18:42:28 2015 anthony geiger
*/

#include "my.h"

int		case_pres(void *argv, t_index *s,
			  const char *format, const t_struc *tab)
{
  (void)*s;
  (void)*tab;
  (void)argv;
  (void)*format;
  my_putchar('%');
  return (1);
}

int		case_sharp2(t_index *s, const char *format,
			    int i, const t_struc *tab)
{
  if (format[s->i + 1] == 'x' || format[s->i + 1] == 'X')
    {
      my_putstr("0x");
      i = i + 2;
    }
  else if (format[s->i + 1] == 'o')
    {
      my_putchar('0');
      i = i + 1;
    }
  while (tab[s->n].c != format[s->i + 1])
    s->n++;
  return (i);
}

int		case_sharp(void *argv, t_index *s,
			   const char *format, const t_struc *tab)
{
  int		i;
  int		ret;

  i = 0;
  ret = 0;
  if (format[s->i + 1] == 'x' || format[s->i + 1] == 'X'
      || format[s->i + 1] == 'o')
    {
      s->n = 0;
      i = case_sharp2(s, format, i, tab);
      ret = i;
      i = (*tab[s->n].ptr_tab)(argv, s, format, tab);
      i = i + ret;
      s->i++;
    }
  return (i);
}

int		case_zero(void *argv, t_index *s,
			  const char *format, const t_struc *tab)
{
  int		i;

  s->nbr = 0;
  i = 0;
  while (format[s->i + 1] >= '0' && format[s->i + 1] <= '9')
    {
      s->nbr = s->nbr * 10 + format[s->i + 1] - '0';
      s->i++;
    }
  if (format[s->i + 1] == 'x' || format[s->i + 1] == 'X'
      || format[s->i + 1] == 'o' || format[s->i + 1] == 'u'
      || format[s->i + 1] == 'd' || format[s->i + 1] == 'i')
    {
      s->p = 1;
      s->n = 0;
      while (tab[s->n].c != format[s->i + 1])
	s->n++;
      i = (*tab[s->n].ptr_tab)(argv, s, format, tab);
      s->i++;
    }
  return (i);
}
