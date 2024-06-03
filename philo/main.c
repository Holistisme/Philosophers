/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:07:25 by aheitz            #+#    #+#             */
/*   Updated: 2024/06/03 10:13:23 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	print_summary(const t_parameters *parameters);

//	* ---------------------- Main program function ---------------------- *	//
//	? --- Checks arguments, and if valid, save transmitted parameters --- ?	//
//	? ---------------- Displays a summary of parameters ---------------- ?	//
//	? ----------------- Makes the philosophers sit down ----------------- ?	//
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
	print_summary(parameters);
	if (sit_philosophers(parameters) == FAILURE)
	{
		free(parameters);
		return (FAILURE);
	}
	free(parameters);
	return (SUCCESS);
}

//	* -------------------- Summary display function -------------------- *	//
//	? - Displays essential information about numbers sent as parameters - ?	//
//	? ----------------- Also displays the end condition ----------------- ?	//
static void	print_summary(const t_parameters *parameters)
{
	printf("\nWelcome to the " BLUE "\"Philosophers\"" RESET " program!\n\n");
	printf("🔢  Number of philosophers at the table: " YELLOW "%d" RESET ".\n",
		parameters->philosophers);
	printf("💀  Time to die is " YELLOW "%d" RESET " milliseconds.\n",
		parameters->time_to_die / 1000);
	printf("🍲  Time to eat is " YELLOW "%d" RESET " milliseconds.\n",
		parameters->time_to_eat / 1000);
	printf("💤  Time to sleep is " YELLOW "%d" RESET " milliseconds.\n",
		parameters->time_to_sleep / 1000);
	if (parameters->meals_to_end)
		printf("🍽   Philosophers have to eat " GREEN "%d" RESET " times.\n\n",
			parameters->meals_to_end);
	else
		printf(RED "🗡   Philosophers will sit until they die.\n\n" RESET);
}
