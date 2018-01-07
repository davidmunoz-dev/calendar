/*
** list_func.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sat Jun 18 11:39:19 2016 David Munoz
** Last update Fri Jul  1 11:16:15 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "calendar.h"

t_meeting	*init_meeting(t_meeting *meeting)
{
  if ((meeting = malloc(sizeof(t_meeting))) == NULL)
    return (cerr_msg_exit("Error: Malloc failed\n", 84));
  meeting->id = 0;
  meeting->city = NULL;
  meeting->date = NULL;
  meeting->people = 0;
  meeting->people2 = 0;
  meeting->people3 = 0;
  meeting->is_actif = MY_FALSE;
  meeting->print = MY_FALSE;
  meeting->next = NULL;
  meeting->prev = NULL;
  return (meeting);
}

t_meeting	*add_meeting(t_meeting *elem, char **tab)
{
  t_meeting		*new_elem;
  t_meeting		*tmp;

  new_elem = create_meeting(tab);
  tmp = elem;
  if (elem == NULL)
    return (new_elem);
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      new_elem->prev = tmp;
    }
  return (elem);
}

t_meeting	*create_meeting(char **tab)
{
  t_meeting		*new_elem;

  if ((new_elem = malloc(sizeof(t_meeting))) == NULL)
    return (cerr_msg(ERROR, ERR_MALL));
  new_elem->city = tab[1];
  new_elem->date = tab[2];
  new_elem->id = my_getnbr(tab[3]);
  new_elem->people = my_getnbr(tab[4]);
  new_elem->people2 = my_getnbr(tab[5]);
  if (tab && tab[6])
    new_elem->people3 = my_getnbr(tab[6]);
  new_elem->is_actif = MY_TRUE;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  return (new_elem);
}
