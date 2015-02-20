/*
** case_tab.c for tab in /home/geiger_a/HOME/PSU_2014_minishell1
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 13 11:16:12 2015 Anthony Geiger
** Last update Tue Jan 13 19:44:50 2015 Anthony Geiger
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"

void	my_find_pwd(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL && my_strncmp(env[i], "PWD", 3) == 1)
    i++;
  if (env[i] == NULL)
    my_putstr("PWD not found\n");
  else
    {
      my_putnstr(env[i], 4);
      my_putchar('\n');
    }
}

int	case_exit(char **env, char *c)
{
  (void)c;
  (void)env;
  return (1);
}

int		case_cd(char **env, char *c)
{
  int	i;
  char	*pass;

  i = 0;
  while (env[i] != NULL && my_strncmp(env[i], "PWD", 3) == 1)
    i++;
  pass = my_strnsdup(c, 3);
  if (pass[0] == '-' && pass[1] == '\0')
    chdir("/home");
  chdir(pass);
  return (0);
}

int	child_fonc_ls(char **env, char **argv, int pid)
{
  int		i;
  char		**path;
  char		*envpath;

  i = 0;
  if (pid == 0)
    {
      while (env[i] != NULL && my_strncmp(env[i], "PATH", 4) == 1)
	i++;
      if (env[i] == NULL)
	{
	  my_putstr("PATH not found");
	  return (0);
	}
      envpath = my_strnsdup(env[i], 5);
      path = my_spe_in_tab(envpath, ':');
      i = 0;
      while (path[i] != NULL)
	{
	  if (execve(my_strconcat(path[i], "/ls"), argv, env) != - 1)
	    return (0);
	  i++;
	}
    }
  return (0);
}

int		case_ls(char **env, char *c)
{
  int		pid;
  int		status;
  char		**argv;

  c = my_strconcat(c, " --color");
  argv = my_word_in_tab(c);
  if ((pid = fork()) == - 1)
    return (1);
  child_fonc_ls(env, argv, pid);
  if (waitpid(pid, &status, 0) == -1)
    return (1);
  return (0);
}
