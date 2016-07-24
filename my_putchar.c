/*
** my_putchar.c for lib in /home/wyzlic_a/blih/Piscine_C_LIB/c_files
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Mar 14 12:03:59 2016 Dimitri Wyzlic
** Last update Sat May 28 11:09:25 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include "header.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
