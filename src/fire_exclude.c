/*
** fire_exclude.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 30 23:49:07 2016 David Munoz
** Last update Fri Jul  1 11:12:08 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "calendar.h"

void		fire_people(int id, t_employee *employee)
{
  t_employee    *tmp;

  tmp = employee;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->is_actif == MY_TRUE && id == tmp->id)
        tmp->is_actif = MY_FALSE;
      tmp = tmp->next;
    }
}

int		find_exclude_people(int room, t_meeting *meeting)
{
  t_meeting     *tmp;

  tmp = meeting;
  tmp = tmp->next;
  while (tmp)
    {
      if (tmp->id == room)
        return (0);
      tmp = tmp->next;
    }
  return (1);
}

int		exclude_people(int id, t_meeting *meeting)
{
  t_meeting     *tmp;

  tmp = meeting;
  tmp = tmp->next;
  while (tmp)
    {
      if (tmp->people == id)
        return (tmp->people = 0);
      else if (tmp->people2 == id)
        return (tmp->people2 = 0);
      else if (tmp->people3 == id)
	return (tmp->people3 = 0);
      tmp = tmp->next;
    }
  return (0);
}

int		check_exclude(int room, char **tab,
			      t_meeting *meeting)
{
  int   i;

  i = 2;
  if (find_exclude_people(room, meeting) == 1)
    return (CAL_ERR);
  while (tab[i])
    {
      exclude_people(my_getnbr(tab[i]), meeting);
      i++;
    }
  return (CAL_OK);
}

int		check_fire(int j, char **tab,
			   t_employee *employee, t_meeting *meeting)
{
  int   i;

  i = 0;
  if (j == FIRE)
    {
      while (tab[i])
        {
          fire_people(my_getnbr(tab[i]), employee);
          i++;
        }
    }
  if (j == EXCLUDE)
    {
      check_exclude(my_getnbr(tab[1]), tab, meeting);
    }
  return (0);
}
