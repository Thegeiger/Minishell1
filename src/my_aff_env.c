/*
** my_aff_env.c for env in /home/geiger_a/rendu/PSU_2014_minishell1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 13:56:40 2015 anthony geiger
** Last update Fri Jan  9 11:23:32 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void	my_aff_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      my_printf("%s\n", env[i]);
      ++i;
    }
}
