/*
** tab_fonc.c<2> for tab in /home/geiger_a/HOME/PSU_2014_minishell1
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 13 10:57:20 2015 Anthony Geiger
** Last update Wed Jan 14 11:36:32 2015 Anthony Geiger
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char	**end_of_tab(char **tmp_tab, int i, int x, char *name)
{
  if ((tmp_tab[i] = malloc(sizeof(char) * my_strlen(name) + 2)) == NULL)
    return (NULL);
  while (name[x])
    {
      tmp_tab[i][x] = name[x];
      ++x;
    }
  tmp_tab[i][x] = '=';
  tmp_tab[i][x + 1] = '\0';
  tmp_tab[i + 1] = NULL;
  return (tmp_tab);
}

char	**my_realloc_tab_str(char **tab, int size, char *name)
{
  char	**tmp_tab;
  int	i;
  int	x;

  i = 0;
  if ((tmp_tab = malloc(sizeof(char **) * size + 1)) == NULL)
    return (NULL);
  while (tab[i])
    {
      if ((tmp_tab[i] = malloc(sizeof(char *) * my_strlen(tab[i]) + 1)) == NULL)
	return (NULL);
      x = 0;
      while (tab[i][x] != 0)
	{
	  tmp_tab[i][x] = tab[i][x];
	  ++x;
	}
      tmp_tab[i][x] = '\0';
      ++i;
    }
  x = 0;
  tmp_tab = end_of_tab(tmp_tab, i, x, name);
  return (tmp_tab);
}

char 	**my_add_to_tab(char *name, char **env)
{
  int	size;
  char	**tab;

  if (name[0] == '*')
    return (env);
  tab = my_word_in_tab(name);
  size = my_tablen(env) + 1;
  if ((env = my_realloc_tab_str(env, size, tab[0])) == NULL)
    return (NULL);
  if (tab[1] != NULL)
    env[size - 1] = my_strconcat(env[size - 1], tab[1]);
  return (env);
}
