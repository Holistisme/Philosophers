/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:00:44 by aheitz            #+#    #+#             */
/*   Updated: 2024/05/31 12:53:15 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

//	* -------------------- Static function prototype -------------------- *	//
static int	save_parameter(const char *argv, unsigned int *parameter);

//	* -------- Function to check the number of arguments entered -------- *	//
//	* ------- If the number of arguments is valid, returns "TRUE" ------- *	//
//	! --- If the number is too low or too high, treats it as an error --- !	//
int	arguments_are_valid(const int argc)
{
	if (argc < 4 || argc > 5)
	{
		if (argc < 4)
			print_stderr("The number of arguments is too low!\n");
		else if (argc > 5)
			print_stderr("The number of arguments is too high!\n");
		return (FALSE);
	}
	return (TRUE);
}

//	* --------------- Parameter initialization function --------------- *	//
//	? ------------ Allocates memory for management structure ------------ ?	//
//	? -------- Saves each parameter while checking its validity -------- ?	//
//	? ------------- Saves additional settings if requested ------------- ?	//
//	* ---------- Returns the management structure thus created ---------- *	//
//	! - If allocation or saving fails, frees memory and returns "NULL" - !	//
t_parameters	*set_parameters(char **argv)
{
	t_parameters	*parameters;

	if (set_allocation((void **)&parameters, sizeof(t_parameters)) == FAILURE)
	{
		print_stderr("Allocation failure to obtain input parameters!\n");
		return (NULL);
	}
	if (save_parameter(argv[1], &parameters->philosophers) == FAILURE
		|| save_parameter(argv[2], &parameters->time_to_die) == FAILURE
		|| save_parameter(argv[3], &parameters->time_to_eat) == FAILURE
		|| save_parameter(argv[4], &parameters->time_to_sleep) == FAILURE
		|| (argv[5]
			&& save_parameter(argv[5], &parameters->meals_to_end) == FAILURE))
	{
		print_stderr("An unsigned integers entered as parameter is invalid!\n");
		free(parameters);
		return (NULL);
	}
	return (parameters);
}

//	* --------------------- Parameter save function --------------------- *	//
//	? ------ Initializes a long integer to check for data overflow ------ ?	//
//	? -------------- Accepts spaces and a single plus sign -------------- ?	//
//	? -------------- Saves each number by adding the unit -------------- ?	//
//	? -------------- Then defines the associated parameter -------------- ?	//
//	* ----------- Returns a "SUCCESS" status if all went well ----------- *	//
//	! ---- In case of non-simple-integer parameter, returns failure ---- !	//
static int	save_parameter(const char *argv, unsigned int *parameter)
{
	unsigned long long	integer;

	integer = 0;
	while (*argv == ' ' || (*argv >= '\t' && *argv <= '\r'))
		++argv;
	if (*argv == '+')
		++argv;
	while (*argv >= '0' && *argv <= '9')
	{
		integer = (integer * 10) + (*argv++ - '0');
		if ((integer) > INT_MAX)
			return (FAILURE);
	}
	if (*argv)
		return (FAILURE);
	*parameter = integer;
	return (SUCCESS);
}
