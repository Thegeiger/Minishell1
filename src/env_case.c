/*
** env_case.c for env in /home/geiger_a/HOME/PSU_2014_minishell1
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 13 11:01:44 2015 Anthony Geiger
** Last update Tue Jan 13 20:32:21 2015 Anthony Geiger
*/

#include "my.h"
#include "mysh.h"

int		my_envset_fonc(char *c, char **env)
{
  int		ret;

  if ((ret = case_unsetenv(c, env)) == 1)
    return (1);
  else if (ret == 0)
    return (0);
  return (2);
}

int	case_env(char **env, char *c)
{
  (void)c;
  my_aff_env(env);
  return (0);
}

int             case_setenv(char *c)
{
  if (my_strncmp(c, "setenv", 6) == 0)
    {
      if (my_strcmp(c, "setenv") == 0)
	{
	  my_putstr("Usage : setenv <env name>\n");
	  return (0);
	}
      else if (c[6] == ' ')
	{
	  return (3);
	}
    }
  return (2);
}

int		case_unsetenv(char *c, char **env)
{
  if (my_strncmp(c, "unsetenv", 8) == 0)
    {
      if (my_strcmp(c, "unsetenv") == 0)
  	{
  	  my_putstr("Usage : unsetenv <env name>\n");
  	  return (0);
  	}
      else if (c[8] == ' ')
  	{
  	  if (my_unsetenv(my_strnsdup(c, 9), env) ==  - 1)
	    {
	      my_putstr("unsetenv error\n");
	      return (1);
	    }
	  return (0);
  	}
    }
  return (2);
}

int	my_unsetenv(char *name, char **env)
{
  int	i;
  int	x;

  i = 0;
  while (env[i] != 0)
    {
      x = 0;
      while (env[i][x] != '=' && env[i][x] != '\0')
	++x;
      if (my_strncmp(env[i], name, x) == 0)
	{
	  remove_str_in_tab(env, i);
	}
      ++i;
    }
  return (0);
}
