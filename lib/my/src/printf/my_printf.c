/*
** my_printf.c for printf in /home/geiger_a/PSU_2014_my_printf
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Thu Nov  6 22:22:04 2014 anthony geiger
** Last update Mon Jan  5 19:22:48 2015 anthony geiger
*/

#include <stdarg.h>
#include "my.h"

void		my_printf3(const char *format, va_list ap, t_index *s,
                           const t_struc *tab)
{
  while (tab[s->n].c != format[s->i])
    {
      s->n++;
      if (s->n > 15)
	{
	  s->i--;
	  break;
	}
    }
  if (s->n <= 15)
    {
      s->res = s->r;
      s->r = (*tab[s->n].ptr_tab)(va_arg(ap, void *), s, format, tab);
      s->r = s->res + s->r;
    }
}

void		my_printf2(const char *format, va_list ap, t_index *s,
			   const t_struc *tab)
{
  while (format[s->i])
    {
      s->n = 0;
      s->nb = 0;
      if (format[s->i] == '%')
  	{
	  s->i++;
	  while (format[s->i] == ' ')
	    s->i++;
	  my_printf3(format, ap, s, tab);
	}
      else
	{
	  my_putchar(format[s->i]);
	  s->r++;
	}
      s->i++;
    }
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  t_index	s;
  static const t_struc	tab[] = { { 's', &case_s }, { 'p', &case_p },
				  { 'd', &case_di },
			  { 'b', &case_b }, { 'x', &case_x }, { 'S', &s_putstr },
			  { 'X', &x_case }, { 'u', &case_u }, { 'i', &case_di },
			  { 'o', &case_o }, { 'c', &case_c }, { '%', &case_pres },
			  { '#', &case_sharp }, { '0', &case_zero }, { 'l', &case_l } };

  s.i = 0;
  s.r = 0;
  s.p = 0;
  va_start(ap, format);
  my_printf2(format, ap, &s, tab);
  va_end(ap);
  return (s.r);
}
