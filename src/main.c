/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 10:02:16 2016 David Munoz
** Last update Fri Jul  1 11:23:52 2016 David Munoz
*/

#include "utils.h"
#include "calendar.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		read_file(t_employee *employee, t_meeting *meeting)
{
  FILE		*file;
  char          *ln;
  size_t        len;

  len = 0;
  ln = NULL;
  if ((file = fdopen(0, "r")) == NULL)
    cerr_exit("Error: fdopen failed\n", 84);
  while (getline(&ln, &len, file) != -1 && my_strncmp(ln, "END", 3) != 0)
    pars_line(ln, employee, meeting);
  if (pclose(file) != 0)
    cerr_exit("Could not run more or other error.\n", 84);
  free(ln);
  return (0);
}

int		main()
{
  t_employee	*employee;
  t_meeting	*meeting;

  employee = init_employee(NULL);
  meeting = init_meeting(NULL);
  read_file(employee, meeting);
  if (meeting->print == MY_TRUE)
    print_meeting(meeting, employee);
  if (employee->print == MY_TRUE)
    print_employee(employee);
  return (CAL_OK);
}
