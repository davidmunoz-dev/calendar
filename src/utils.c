/*
** utils.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 30 16:51:57 2016 David Munoz
** Last update Fri Jul  1 11:10:18 2016 David Munoz
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "calendar.h"

void		*cerr_msg_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int		cerr_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int		get_nbr_coma(int people, int people2,
			     int people3, t_employee *employee)
{
  t_employee    *tmp;
  int           coma;

  coma = 0;
  tmp = employee;
  while (tmp)
    {
      if (tmp->is_actif == MY_TRUE)
        {
          if (people == tmp->id
              || people2 == tmp->id
              || people3 == tmp->id)
            coma++;
        }
      tmp = tmp->next;
    }
  return (coma);
}
