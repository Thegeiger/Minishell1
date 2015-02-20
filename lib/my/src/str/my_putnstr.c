/*
** my_putnstr.c for my_putnstr.c in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 18:44:02 2015 Anthony Geiger
** Last update Tue Jan  6 18:47:36 2015 Anthony Geiger
*/

#include "my.h"

void	my_putnstr(char *str, int nb)
{
  int	i;

  i = nb;
  if (nb >= my_strlen(str))
    return ;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
