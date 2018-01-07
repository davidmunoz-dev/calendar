/*
** list_func.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sat Jun 18 11:39:19 2016 David Munoz
** Last update Fri Jul  1 11:18:44 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "calendar.h"

t_employee	*init_employee(t_employee *employee)
{
  if ((employee = malloc(sizeof(t_employee))) == NULL)
    return (cerr_msg_exit("Error: Malloc failed\n", 84));
  employee->id = 0;
  employee->last_name = NULL;
  employee->first_name = NULL;
  employee->position = NULL;
  employee->city = NULL;
  employee->is_actif = MY_FALSE;
  employee->print = MY_FALSE;
  employee->next = NULL;
  employee->prev = NULL;
  return (employee);
}

t_employee	*add_employee(t_employee *elem, char **tab)
{
  t_employee		*new_elem;
  t_employee		*tmp;

  new_elem = create_employee(tab);
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

t_employee	*create_employee(char **tab)
{
  t_employee		*new_elem;

  if ((new_elem = malloc(sizeof(t_employee))) == NULL)
    return (cerr_msg(ERROR, ERR_MALL));
  new_elem->first_name = tab[1];
  new_elem->last_name = tab[2];
  new_elem->position = tab[3];
  new_elem->city = tab[4];
  new_elem->id = my_getnbr(tab[5]);
  new_elem->is_actif = MY_TRUE;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  return (new_elem);
}
