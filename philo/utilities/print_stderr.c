/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:49:38 by aheitz            #+#    #+#             */
/*   Updated: 2024/05/31 15:32:17 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	* -------------------- Static function prototype -------------------- *	//
static size_t	get_size(const char *string);

//	* ------------ Error write function on associated output ------------ *	//
//	? ------------------- Informs of error encounter ------------------- ?	//
//	? -------------- Writes the transmitted error message -------------- ?	//
void	print_stderr(const char *string)
{
	if (write(STDERR, "Error\n", 6) == UNSUCCESSFUL)
		return ;
	write(STDERR, string, get_size(string));
}

//	* ----- Function for calculating the size of a character string ----- *	//
//	? - If address exists, up to the end character, increases the index - ?	//
//	* ------------------- Returns the calculated size ------------------- *	//
static size_t	get_size(const char *string)
{
	size_t	index;

	index = 0;
	if (string)
		while (string[index])
			++index;
	return (index);
}
