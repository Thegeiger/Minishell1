/*
** my_strlen.c for strlen in /home/geiger_a/lib/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 19:29:05 2015 anthony geiger
** Last update Wed Jan  7 16:07:49 2015 Anthony Geiger
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
