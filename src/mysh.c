/*
** mysh.c for minishell in /home/geiger_a/rendu/PSU_2014_minishell1
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Fri Jan  2 18:43:21 2015 anthony geiger
** Last update Fri Feb 20 11:37:33 2015 anthony geiger
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"

int		exec_child(char **path, char *exec, char **argv, char **env)
{
  int		i;

  i = 0;
  while (path[i] != NULL)
    {
      if (execve(my_strconcat(path[i], exec), argv, env) != - 1)
	return (0);
      i++;
    }
  if (execve(argv[0], argv, env) == - 1)
    {
      my_putstr(argv[0]);
      my_putstr(": command not found\n");
    }
  exit(1);
  return (0);
}

int		child_fonc(char **env, char **argv)
{
  char		*exec;
  char		**path;
  int		i;
  char		*envpath;

  i = 0;
  exec = my_strconcat("/" ,argv[0]);
  while (env[i] != NULL && my_strncmp(env[i], "PATH", 4) == 1)
    i++;
  if (env[i] == NULL)
    {
      my_putstr("PATH not found");
      return (0);
    }
  envpath = my_strnsdup(env[i], 5);
  path = my_spe_in_tab(envpath, ':');
  exec_child(path, exec, argv, env);
  return (0);
}

int		my_exec_fonc(char *c, char **env, t_alias *alias, int i)
{
  int		pid;
  int		status;
  char		**argv;

  argv = my_word_in_tab(c);
  if ((pid = fork()) == - 1)
    return (1);
  if (alias != NULL)
    {
      while (alias[i].new_name != NULL && my_strcmp(alias[i].new_name, c) != 0)
	i++;
      if (alias[i].name != NULL && my_strcmp(alias[i].new_name, c) == 0)
	{
	  if (pid == 0)
	    child_fonc(env, my_word_in_tab(alias[i].name));
	  if (waitpid(pid, &status, 0) == -1)
	    return (1);
	  exit(1);
	}
    }
  if (pid == 0)
    child_fonc(env, argv);
  if (waitpid(pid, &status, 0) == -1)
    return (1);
  return (0);
}

int			ptr_tab_fonc(char *c, char **env, t_alias *alias)
{
  static const t_ptrtab	tab[] =
    {
      { "exit", &case_exit },
      { "env", &case_env },
      { "cd", &case_cd },
      { "ls", &case_ls }
    };
  int			i;

  i = 0;
  while (i != 4 && my_strcmp(c, tab[i].str) != 0)
    i++;
  if (i < 4)
    {
      if (tab[i].ptr_tab(env, c) == 1)
	return (1);
    }
  else
    my_exec_fonc(c, env, alias, 0);
  return (0);
}

int			minishell1(char **env, char *c, t_alias **alias)
{
  int			ret;

  if ((ret = my_envset_fonc(c, env)) == 1)
    return (1);
  else if (ret == 0)
    return (0);
  if (ptr_tab_fonc(c, env, *alias) == 1)
    return (1);
  return (0);
}
