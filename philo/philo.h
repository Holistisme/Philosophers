/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:07:37 by aheitz            #+#    #+#             */
/*   Updated: 2024/06/03 22:16:42 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define UNSUCCESSFUL -1
# define SUCCESSFUL 0
# define FALSE 0
# define TRUE 1
# define STDERR 2
# define MILLISECOND 1000
# define INT_MAX 2147483647
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define FAILURE EXIT_FAILURE
# define SUCCESS EXIT_SUCCESS
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef int	t_boolean;

//	* ---------- The storage structure for supplied parameters ---------- *	//
typedef struct s_parameters
{
	unsigned int	philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meals_to_end;
}	t_parameters;

//	* --------- The structure of data received by a philosopher --------- *	//
typedef struct s_philosopher
{
	unsigned int	index;
	t_parameters	*parameters;
	pthread_t		*address;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philosopher;

//	* ------------------------ Program functions ------------------------ *	//
//	? --------------------- Main program functions --------------------- ?	//
int				main(int argc, char **argv);
int				arguments_are_valid(const int argc);
t_parameters	*set_parameters(char **argv);

//	? -------------------- Program utility functions -------------------- ?	//
int				set_allocation(void **target, const size_t size);
void			print_stderr(const char *string);

//	? ------------------ The functions of philosophers ------------------ ?	//
int				sit_philosophers(t_parameters *parameters);
void			*philo_routine(void *arg);
int				monitoring(pthread_t *pthreads, t_philosopher **philosophers);

#endif