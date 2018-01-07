/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:13:03 2016 David Munoz
** Last update Thu Jun 30 16:28:01 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

int	my_revlist_synthesis(t_list **begin)
{
  t_list *first;
  t_list *suivant;
  t_list *prev;

  prev = NULL;
  first = *begin;
  while (first)
    {
      suivant = first->next;
      first->next = prev;
      prev = first;
      first = suivant;
    }
  *begin = prev;
  return (0);
}

t_list	*my_findnodeeqinlist_synthesis(t_list *begin, void *data_ref, int (*cmp)())
{
  t_list *tmp;

  tmp = begin;
  while (tmp)
    {
      if ((*cmp)(tmp->data, data_ref) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
