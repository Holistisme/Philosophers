/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:07:25 by aheitz            #+#    #+#             */
/*   Updated: 2024/05/31 15:41:08 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

//	* ---------------------- Main program function ---------------------- *	//
//	? --- Checks arguments, and if valid, save transmitted parameters --- ?	//
//	? ----------------- Finally frees these parameters ----------------- ?	//
//	* ----- If all goes perfectly, terminates program successfully ----- *	//
//	! - If invalid arguments or failed initialization, exits in failure - !	//
int	main(int argc, char **argv)
{
	t_parameters	*parameters;

	parameters = NULL;
	if (arguments_are_valid(--argc))
		parameters = set_parameters(argv);
	if (!parameters)
		return (FAILURE);
	free(parameters);
	return (SUCCESS);
}
