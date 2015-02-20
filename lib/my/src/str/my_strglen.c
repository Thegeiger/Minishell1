/*
** my_strglen.c<2> for my_strglen in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Wed Jan  7 16:04:40 2015 Anthony Geiger
** Last update Wed Jan  7 19:53:17 2015 Anthony Geiger
*/

#include "my.h"

int		my_strglen(long *a)
{
  int		i;

  i = 0;
  while (a[i])
    ++i;
  return (i);
}
