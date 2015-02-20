/*
** case_printf_part2.c for case2 in /home/geiger_a/rendu/PSU_2014_my_printf/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 13:46:33 2014 anthony geiger
** Last update Mon Jan  5 18:42:19 2015 anthony geiger
*/

#include "my.h"

int		case_b(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long          n;
  int		r;

  (void)*s;
  (void)*format;
  (void)*tab;
  n = (long)argv;
  r = convert_base_deci_2((int)n);
  return (r);
}

int		case_di(void *argv, t_index *s,
			const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)tab;
  (void)format;
  n = (long)argv;
  if (s->p == 2)
    r = my_lputnbr(n);
  else
    r = my_putnbrs((int)n, s->p, s->nbr);
  s->p = 0;
  return (r);
}

int		case_o(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)*tab;
  (void)*s;
  (void)*format;
  n = (long)argv;
  if (s->p == 2)
    convert_base_deci_8_lunint((long unsigned int)n);
  else
    r = convert_base_deci_8_unint((unsigned int)n);
  return (r);
  s->p = 0;
}

int		x_case(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)*tab;
  (void)*s;
  (void)*format;
  n = (long)argv;
  if (s->p == 2)
    r = convert_base_deci_16_lun((long unsigned int)n, "0123456789ABCDEF");
  else
    r = convert_base_deci_16_un((unsigned int)n, "0123456789ABCDEF");
  return (r);
}

int		case_u(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)*s;
  (void)*tab;
  (void)*format;
  n = (long)argv;
  if (s->p == 2)
    my_lunputnbr((long unsigned int)n);
  else
    r = my_unputnbrs((unsigned int)n, s->p, s->nbr);
  s->p = 0;
  return (r);
}
