/*
** info.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 30 23:57:49 2016 David Munoz
** Last update Fri Jul  1 11:15:50 2016 David Munoz
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "calendar.h"

int		check_info(char *tab)
{

  if (my_strncmp(tab, "info_meetings", 13) == 0)
    return (INFO_MEET);
  else if (my_strncmp(tab, "info_employees", 14) == 0)
    return (INFO_EMPL);
  return (CAL_ERR);
}

void		find_people(int people, int people2,
			    int people3, t_employee *employee)
{
  t_employee    *tmp;
  int		coma;

  coma = get_nbr_coma(people, people2, people3, employee) - 1;
  tmp = employee;
  while (tmp)
    {
      if (tmp->is_actif == MY_TRUE)
	{
	  if (people == tmp->id
	      || people2 == tmp->id
	      || people3 == tmp->id)
	    {
	      printf(" %s %s", tmp->last_name, tmp->first_name);
	      if (coma > 0)
		printf(",");
	      coma--;
	    }
	}
      tmp = tmp->next;
    }
}

void		print_meeting(t_meeting *meeting, t_employee *employee)
{
  t_meeting    *tmp;

  tmp = meeting;
  while (tmp)
    {
      if (tmp->is_actif == MY_TRUE)
        {
	  printf("******************************\nMEETING\n");
          printf("date:  %s\nplace:  %s ", tmp->date, tmp->city);
          printf("with");
	  find_people(tmp->people, tmp->people2, tmp->people3,employee);
          printf("\n");
        }
      tmp = tmp->next;
    }
}

void		print_employee(t_employee *employee)
{
  t_employee    *tmp;

  tmp = employee;
  while (tmp != NULL)
    {
      if (tmp->is_actif == MY_TRUE)
        {
	  printf("******************************\n");
	  printf("%s %s\n",tmp->first_name, tmp->last_name);
	  printf("position:  %s\n", tmp->position);
	  printf("city:  %s", tmp->city);
          printf("\n");
        }
      tmp = tmp->next;
    }
}

void		print_info(int j, t_meeting *meeting, t_employee *employee)
{
  if (j == INFO_MEET)
    meeting->print = MY_TRUE;
  if (j == INFO_EMPL)
    employee->print = MY_TRUE;
}
