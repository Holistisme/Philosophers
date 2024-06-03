/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:14:55 by aheitz            #+#    #+#             */
/*   Updated: 2024/06/03 22:19:41 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

//	* -------------------- Static function prototype -------------------- *	//
static int	sit_the_philosopher(pthread_t *pthreads,
				t_philosopher **philosopher, const unsigned int index,
				t_parameters *parameters);
static int	readjust_the_forks(t_philosopher **philosopher,
				const unsigned int index);
static int	exit_failure(pthread_t *pthreads, t_philosopher **philosophers);

//	* ---------------- Function for seating philosophers ---------------- *	//
//	? ------ Allocates threads and identities for each philosopher ------ ?	//
//	? ------ For each philosopher, transmits number and parameters ------ ?	//
//	* ---- Continues the program, keeping an eye on the philosophers ---- *	//
//	! ---- If an allocation error is encountered, returns “FAILURE” ---- !	//
int	sit_philosophers(t_parameters *parameters)
{
	pthread_t		*pthreads;
	t_philosopher	**philosophers;
	unsigned int	index;

	if (set_allocation((void **)&pthreads, sizeof(pthread_t)
			* parameters->philosophers) == FAILURE)
	{
		print_stderr("Threads allocation error!\n");
		return (FAILURE);
	}
	else if (set_allocation((void **)&philosophers, sizeof(t_philosopher)
			* parameters->philosophers) == FAILURE)
	{
		print_stderr("Error when allocating philosophers!\n");
		return (exit_failure(pthreads, NULL));
	}
	index = 0;
	while (index < parameters->philosophers)
	{
		if (sit_the_philosopher(pthreads, philosophers, index++, parameters)
			== FAILURE)
			return (exit_failure(pthreads, philosophers));
		usleep(MILLISECOND);
	}
	return (monitoring(pthreads, philosophers));
}

//	* ------------- Intialization function of a philosopher ------------- *	//
//	? ---------- Allocates memory for philosopher information ---------- ?	//
//	? ----------- Stores thread address, index and parameters ----------- ?	//
//	? ---------------- Launches and detaches the thread ---------------- ?	//
//	* -------------- Returns the result of fork adjustment -------------- *	//
//	! ------ If an operation or allocation fails, return "FAILURE" ------ !	//
static int	sit_the_philosopher(pthread_t *pthreads,
				t_philosopher **philosopher, const unsigned int index,
				t_parameters *parameters)
{
	if (set_allocation((void **)&philosopher[index], sizeof(t_philosopher))
		== SUCCESS)
	{
		philosopher[index]->address = &pthreads[index];
		philosopher[index]->index = index + 1;
		philosopher[index]->parameters = parameters;
		if (pthread_create(&pthreads[index], NULL,
				philo_routine, philosopher[index]) == SUCCESSFUL)
		{
			if (pthread_detach(pthreads[index]) == SUCCESSFUL)
				return (readjust_the_forks(philosopher, index));
			print_stderr("Error, a philosopher's detachment has failed!\n");
		}
		else
			print_stderr("Error creating a thread!\n");
		free(philosopher[index]);
	}
	else
		print_stderr("Error when allocating a philosopher!\n");
	return (FAILURE);
}

//	* --------------- Function to readjust table cutlery --------------- *	//
//	? -- Each time a call is made, a new fork is allocated and created -- ?	//
//	? ------- The fork to the left of the last philosopher is set ------- ?	//
//	? ------------- The fork to his right is the first one ------------- ?	//
//	? ----- The previous philosopher gets the new fork on his right ----- ?	//
//	* -------------- If all goes well, returns the success -------------- *	//
//	! ---- If allocation or mutex creation fails, returns "FAILURE" ---- !	//
static int	readjust_the_forks(t_philosopher **philosopher,
				const unsigned int index)
{
	pthread_mutex_t	*new_fork;

	if (set_allocation((void **)&new_fork, sizeof(pthread_mutex_t)) == SUCCESS)
	{
		if (pthread_mutex_init(new_fork, NULL) == SUCCESSFUL)
		{
			philosopher[index]->left_fork = new_fork;
			philosopher[index]->right_fork = philosopher[0]->left_fork;
			if (index)
				philosopher[index - 1]->right_fork = new_fork;
			return (SUCCESS);
		}
		free(new_fork);
		print_stderr("Error when creating a mutex for a fork!\n");
	}
	else
		print_stderr("Error when allocating memory for a fork!\n");
	return (FAILURE);
}

//	* --------------- Cleanup and error feedback function --------------- *	//
//	? ------------------- Frees threads if available ------------------- ?	//
//	? ---------- Frees each philosopher and their list, if any ---------- ?	//
//	! --------------------- Returns "FAILURE" only --------------------- !	//
static int	exit_failure(pthread_t *pthreads, t_philosopher **philosophers)
{
	int	index;

	index = 0;
	if (pthreads)
		free(pthreads);
	if (philosophers)
	{
		while (philosophers[index])
		{
			if (philosophers[index]->left_fork)
			{
				free(philosophers[index]->left_fork);
				philosophers[index]->left_fork = NULL;
			}
			free(philosophers[index++]);
		}
		free(philosophers);
	}
	return (FAILURE);
}
