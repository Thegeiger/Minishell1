/*
** remove_str_in_tab.c for remove_str_in_tab in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Wed Jan  7 10:45:35 2015 Anthony Geiger
** Last update Wed Jan  7 10:47:21 2015 Anthony Geiger
*/

#include "my.h"

void    remove_str_in_tab(char **tab, int x)
{
  int   i;

  i = x;
  while (tab[i])
    {
      tab[i] = tab[i + 1];
      i++;
    }
}
