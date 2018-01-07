/*
** dante.h for  in /include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu May  5 12:32:55 2016 David Munoz
** Last update Thu Jun 30 22:49:33 2016 David Munoz
*/

#ifndef UTILS_H_
# define UTILS_H_

typedef char    t_my_bool;

/*
** Include header files
*/
# define _BSD_SOURCE
# define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"

/*
** Color macro definition
*/
# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define PURPLE                 "\033[1;35m"
# define CYAN                   "\033[1;36m"
# define BROWN                  "\033[0;33m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define BLANK                  "\033[0m"

/*
** Error macro definition
*/
# define	ERROR			RED"Error "BLANK
# define	ERR_USAGE		RED"on usage\nUse the parameter '-h' for help\n"BLANK
# define	ERR_MALL		RED": Malloc failed\n"BLANK
# define	ERR_OPEN		RED": Open failed\n"BLANK
# define	ERR_FILE		RED": Wrong file\n"BLANK
# define	MY_TRUE			1
# define	MY_FALSE		0

/*
** Macro definition
*/
# define	CAL_OK		0
# define	CAL_ERR		-1
# define	BUFF_SIZE	4096

#endif /* UTILS_H_ ! */
