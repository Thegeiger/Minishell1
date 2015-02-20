/*
** my_prompt.c<2> for prompt in /home/geiger_a/HOME/PSU_2014_minishell1
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 13 11:07:14 2015 Anthony Geiger
** Last update Tue Jan 13 19:52:34 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void	       	my_prompt(char **env)
{
  static int	size = 1;
  char		*user;
  int		i;

  i = 0;
  while (env[i] != NULL && my_strncmp(env[i], "USER=", 5) == 1)
    i++;
  if (env[i] == NULL)
    my_putstr("user_unknow");
  else
    {
      my_putstr("\033[32m");
      user = my_strnsdup(env[i], 5);
      my_putstr(user);
      free(user);
    }
  my_putchar(' ');
  my_putstr("\033[31m");
  my_putstr("$>");
  my_putnbr(size);
  my_putstr("\033[0m");
  my_putchar(' ');
  size++;
}
