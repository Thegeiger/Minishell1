/*
** my_strncmy.c for my_strncmp in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 18:19:54 2015 Anthony Geiger
** Last update Tue Jan  6 18:41:48 2015 Anthony Geiger
*/

int	my_strncmp(char *a, char *b, int nb)
{
  int	i;

  i = 0;
  while (a[i] != '\0' && b[i] != '\0' && i != nb)
    {
      if (a[i] == b[i])
	i++;
      else
	return (1);
    }
  return (0);
}
