/*
** putchar.c for putchar in /home/geiger_a/program_utile
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Oct 27 11:17:59 2014 anthony geiger
** Last update Wed Jan  7 12:19:22 2015 Anthony Geiger
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == - 1)
    {
      if (write(2, "my_putchar error\n", 1) == - 1)
	exit(1);
      exit(1);
    }
}
