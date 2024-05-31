/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:07:37 by aheitz            #+#    #+#             */
/*   Updated: 2024/05/31 15:36:34 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define UNSUCCESSFUL -1
# define FALSE 0
# define TRUE 1
# define STDERR 2
# define INT_MAX 2147483647
# define FAILURE EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//	* ---------- The storage structure for supplied parameters ---------- *	//
typedef struct s_parameters
{
	unsigned int	philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meals_to_end;
}	t_parameters;

//	* ------------------------ Program functions ------------------------ *	//
//	? --------------------- Main program functions --------------------- ?	//
int				main(int argc, char **argv);
int				arguments_are_valid(const int argc);
t_parameters	*set_parameters(char **argv);

//	? -------------------- Program utility functions -------------------- ?	//
int				set_allocation(void **target, const size_t size);
void			print_stderr(const char *string);

#endif