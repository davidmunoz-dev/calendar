/*
** parsing.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/calendar/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 30 17:26:47 2016 David Munoz
** Last update Fri Jul  1 11:15:07 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "calendar.h"

int		check_type(char *tab)
{
  if (my_strncmp(tab, "new_employee", 12) == 0)
    return (NEW_EMPLOYEE);
  else if (my_strncmp(tab, "new_meeting", 11) == 0)
    return (NEW_MEETING);
  else if (my_strncmp(tab, "exclude", 7) == 0)
    return (EXCLUDE);
  else if (my_strncmp(tab, "fire", 4) == 0)
    return (FIRE);
  return (CAL_ERR);
}

int		check_charac(char **tab, int type)
{
  if (type == NEW_EMPLOYEE)
    {
      if (my_str_isalpha(tab[1]) == 0
	  || my_str_isalpha(tab[2]) == 0
	  || my_str_isalpha(tab[3]) == 0
	  || my_str_islphanumore(tab[4]) == 0
	  || my_str_isnum(tab[5]) == 0)
	return (-1);
    }
  else if (type == NEW_MEETING)
    {
      if (my_str_islphanumore(tab[1]) == 0
  	  || my_str_islphanumore(tab[2]) == 0
  	  || my_str_isnum(tab[3]) == 0
  	  || my_str_isnum(tab[4]) == 0)
	return (-1);
    }
  return (0);
}

int		complete_info(int j, char **tab,
			      t_employee *employee, t_meeting *meeting)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  if (j == NEW_EMPLOYEE && i == 6)
    {
      if ((check_charac(tab, NEW_EMPLOYEE)) == CAL_ERR)
	return (CAL_ERR);
      employee = add_employee(employee, tab);
    }
  else if (j == NEW_MEETING && i >= 6)
    {
      if ((check_charac(tab, NEW_MEETING)) == CAL_ERR)
  	return (CAL_ERR);
      meeting = add_meeting(meeting, tab);
    }
  return (CAL_OK);
}

int		get_info(char **tab, t_employee *employee, t_meeting *meeting)
{
  int	j;

  j = check_type(tab[0]);
  complete_info(j, tab, employee, meeting);
  check_fire(j, tab, employee, meeting);
  j = 0;
  if ((j = check_info(tab[0])) == -1)
    return (CAL_ERR);
  print_info(j, meeting, employee);
  return (CAL_OK);
}

int		pars_line(char *str, t_employee *employee, t_meeting *meeting)
{
  char	**tab;

  if ((tab = malloc(BUFF_SIZE)) == NULL)
    cerr_exit("Error: Malloc failed", 84);
  tab = my_str_to_wordtab(str, ' ');
  get_info(tab, employee, meeting);
  return (0);
}
