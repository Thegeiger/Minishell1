/*
** case_printf_part1.c for case1 in /home/geiger_a/rendu/PSU_2014_my_printf/test
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 13:33:37 2014 anthony geiger
** Last update Mon Jan  5 18:42:06 2015 anthony geiger
*/

#include "my.h"

int		s_putstr(void *argv, t_index *s,
			 const char *format, const t_struc *tab)
{
  int		i;
  char		*str;

  (void)*s;
  (void)*format;
  (void)*tab;
  str = argv;
  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
	convert_base_deci_octal(str[i], "01234567");
      else
	my_putchar(str[i]);
      i++;
    }
  return (i);
}

int		case_p(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)*s;
  (void)*format;
  (void)*tab;
  n = (long)argv;
  r = convert_base_deci_16(n, "0123456789abcdef");
  return (r);
}

int		case_x(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		n;
  int		r;

  (void)*s;
  (void)*format;
  (void)*tab;
  n = (long)argv;
  if (s->p == 2)
    r = convert_base_deci_16_lun((long unsigned int)n, "0123456789abcdef");
  else
    r = convert_base_deci_16_un((unsigned int)n, "0123456789abcdef");
  return (r);
}

int		case_c(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		c;

  (void)*s;
  (void)*format;
  (void)*tab;
  c = (long)argv;
  my_putchar((char)c);
  return (1);
}

int		case_s(void *argv, t_index *s,
		       const char *format, const t_struc *tab)
{
  long		*str;
  int		r;

  str = argv;
  (void)*format;
  (void)*tab;
  if (str == 0)
    {
      my_putstr("(null)");
      return (6);
    }
  (void)*s;
  r = my_putstr((char *)str);
  return (r);
}
