/*
** my_spe_in_tab.c for spé_tab in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 23:55:35 2015 anthony geiger
** Last update Thu Jan 15 18:50:36 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"

int	my_pstrlen_spe(char *str, char sep)
{
  int	i;

  i = 0;
  while (str[i] != sep && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    i++;
  return (i);
}

char	**loop_condition_spe(char **tab, t_win *wit, char *str, char sep)
{
  if (str[wit->nb] == sep)
    {
      tab[wit->i][wit->j] = '\0';
      wit->i++;
      wit->nb++;
      wit->j = 0;
    }
  else
    {
      tab[wit->i][wit->j] = str[wit->nb];
      wit->nb++;
      wit->j++;
    }
  return (tab);
}

char	**my_word_in_tab_base_sep(char *str, t_win *wit, char sep)
{
  char	**tab;

  tab = malloc((wit->word + 1) * sizeof(char **));
  if (tab == NULL)
    return (NULL);
  while (wit->word)
    {
      tab[wit->i] = malloc((my_pstrlen_spe(&str[wit->nb], sep) + 1) * sizeof(char *));
      if (tab[wit->i] == NULL)
	return (NULL);
      wit->nb = wit->nb + my_pstrlen_spe(&str[wit->nb], sep);
      wit->word--;
      wit->i++;
    }
  tab[wit->i] = NULL;
  wit->lines = wit->i;
  wit->nb = 0;
  wit->i = 0;
  while (str[wit->nb])
    tab = loop_condition_spe(tab, wit, str, sep);
  tab[wit->i][wit->j] = '\0';
  return (tab);
}

char     **my_spe_in_tab(char *str, char sep)
{
  int   i;
  int   word;
  t_win struc;

  i = 0;
  word = 1;
  struc.j = 0;
  struc.i = 0;
  struc.nb = 0;
  while (str[i])
    {
      if (str[i] == sep)
        {
          i++;
          word++;
          while (str[i] == sep)
	    exit(1);
        }
      else
        i++;
    }
  struc.word = word;
  return (my_word_in_tab_base_sep(str, &struc, sep));
}
