/*
** main.c for main in /home/geiger_a/rendu/PSU_2014_minishell1/src
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 11:08:30 2015 anthony geiger
** Last update Thu Jan 15 20:33:27 2015 Anthony Geiger
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

int	alias_tab(char *bash, char **tab, int i, t_alias *alias)
{
  if (my_strncmp(bash, "alias", 5) == 0 && bash[5] == ' ')
    {
      tab = my_spe_in_tab(my_strnsdup(bash, 6), '=');
      alias[i].name = my_strdup(tab[1]);
      alias[i].new_name = my_strdup(tab[0]);
    }
  else
    {
      my_putstr("Bad alias file pleas read the README.txt and change it\n");
      return (1);
    }
  free(bash);
  return (0);
}

int		my_take_alias(t_alias *alias)
{
  int		fd;
  char		*bash;
  int		i;
  char		**tab;

  i = 0;
  tab = 0;
  if ((fd = open(".alias", O_RDONLY)) == - 1)
    return (1);
  while ((bash = get_next_line(fd)) != NULL)
    {
      if (bash[0] == '\0')
	break ;
      if (alias_tab(bash, tab, i, alias) == 1)
	return (1);
      i++;
    }
  if (bash == NULL)
    {
      my_putstr("Bad alias file pleas read the README.txt and change it\n");
      return (1);
    }
  alias[i].name = 0;
  alias[i].new_name = 0;
  return (0);
}

int		my_read_bash(t_alias **alias)
{
  int		fd;
  char		*bash;
  int		i;

  i = 0;
  if ((fd = open(".alias", O_RDONLY)) == - 1)
    {
      alias[i] = NULL;
      my_putstr("You can create a .alias please read the README.txt\n");
      return (2);
    }
  while ((bash = get_next_line(fd)) != NULL)
    {
      if (my_strncmp(bash, "alias", 5) == 0)
	i++;
      free(bash);
    }
  if ((*alias = malloc(sizeof(t_alias) * i + 1)) == NULL)
    return (1);
  if (my_take_alias(*alias) == 1)
    return (1);
  return (0);
}

int		loop_main(char *c, int ret, t_alias **alias, char **env)
{
  int		exit_boole;

  exit_boole = 0;
  while (exit_boole == 0)
    {
      my_prompt(env);
      if ((c = get_next_line(0)) == NULL)
	return (1);
      if (c[0] == '\0')
	continue ;
      if ((ret = case_setenv(c)) == 0)
	continue ;
      else if (ret == 3)
	{
	  if ((env = my_add_to_tab(my_strnsdup(c, 7), env)) == NULL)
	    return (1);
	  continue ;
	}
      if ((exit_boole = minishell1(env, c, alias)) == 1)
	return (1);
    }
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  char		*c;
  int		ret;
  t_alias	*alias;

  (void)argc;
  (void)argv;
  ret = 0;
  c = NULL;
  if (my_read_bash(&alias) == 1)
    return (1);
  if (loop_main(c, ret, &alias, env) == 1)
    return (1);
  return (0);
}
