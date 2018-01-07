/*
** palindrome.h for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:11:31 2016 David Munoz
** Last update Fri Jul  1 11:16:30 2016 David Munoz
*/

#ifndef CALENDAR_H_
# define CALENDAR_H_

typedef struct	s_employee	t_employee;
typedef struct	s_meeting	t_meeting;

struct		s_employee
{
  int		id;
  char		*last_name;
  char		*first_name;
  char		*position;
  char		*city;
  t_my_bool	is_actif;
  t_my_bool	print;
  t_employee	*next;
  t_employee	*prev;
};

struct		s_meeting
{
  int		id;
  char		*city;
  char		*date;
  int		people;
  int		people2;
  int		people3;
  t_my_bool	is_actif;
  t_my_bool	print;
  t_meeting	*next;
  t_meeting	*prev;
};

/*
** Some macros
*/
# define	NEW_EMPLOYEE	1
# define	NEW_MEETING	2
# define	INVITE		3
# define	EXCLUDE		4
# define	INFO_EMPLOYEE	5
# define	INFO_MEETING	6
# define	CANCEL		7
# define	FIRE		8
# define	INFO_MEET	9
# define	INFO_EMPL	10

/*
** main
*/
int	read_file();

/*
** utils
*/
void    *cerr_msg_exit(char *log, int status);
int     cerr_exit(char *log, int status);
int     get_nbr_coma(int people, int people2, int people3, t_employee *employee);

/*
** parsing
*/
int     pars_line(char *str, t_employee *employee, t_meeting *meeting);

/*
** employee list func
*/
t_employee      *init_employee(t_employee *employee);
t_employee	*add_employee(t_employee *elem, char **tab);
t_employee	*create_employee(char **tab);

/*
** meeting list func
*/
t_meeting	*init_meeting(t_meeting *meeting);
t_meeting	*add_meeting(t_meeting *elem, char **tab);
t_meeting	*create_meeting(char **tab);

/*
** fire_exclude
*/
int             check_fire(int j, char **tab, t_employee *employee, t_meeting *meeting);

/*
** info
*/
int     check_info(char *tab);
void	print_info(int j, t_meeting *meeting, t_employee *employee);
void    print_employee(t_employee *employee);
void    print_meeting(t_meeting *meeting, t_employee *employee);

#endif /* CALENDAR_H_ ! */
