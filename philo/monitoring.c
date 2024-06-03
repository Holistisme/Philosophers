/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:17:27 by aheitz            #+#    #+#             */
/*   Updated: 2024/06/03 22:12:44 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

//	* ------- Future monitoring function for philosophers' states ------- *	//
//	? --------- Wait and frees everything because I don't know --------- ?	//
//	* ----------------- Automatically return "SUCCESS" ----------------- *	//
int	monitoring(pthread_t *pthreads, t_philosopher **philosophers)
{
	int	index;

	sleep(7);
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
	return (SUCCESS);
}
