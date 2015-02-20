/*
** my_tablen.c for my_tablen in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Wed Jan  7 15:42:12 2015 Anthony Geiger
** Last update Wed Jan  7 20:57:10 2015 Anthony Geiger
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}
