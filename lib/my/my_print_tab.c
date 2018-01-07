/*
** my_print_tab.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/SBMLparser/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 13 15:18:56 2016 David Munoz
** Last update Fri Jul  1 10:20:13 2016 David Munoz
*/

#include <stdio.h>
#include "my.h"

void	print_tab(char **tab)
{
  int   i;
  int   j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
        {
          my_putchar(tab[i][j]);
          j++;
        }
      my_putchar('\n');
      i++;
    }
}
