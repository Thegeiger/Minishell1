/*
** case_printf_part4.c for case4 in /home/geiger_a/PSU_2014_my_printf
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Nov 15 15:14:11 2014 anthony geiger
** Last update Mon Jan  5 18:42:38 2015 anthony geiger
*/

#include "my.h"

int		case_l(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  int		i;

  i = 0;
  if (format[s->i + 1] == 'x' || format[s->i + 1] == 'X'
      || format[s->i + 1] == 'o' || format[s->i + 1] == 'd'
      || format[s->i + 1] == 'i' || format[s->i + 1] == 'u')
    {
      s->p = 2;
      s->n = 0;
      while (tab[s->n].c != format[s->i + 1])
	s->n++;
      i = (*tab[s->n].ptr_tab)(argv, s, format, tab);
      s->i++;
    }
  return (i);
}
