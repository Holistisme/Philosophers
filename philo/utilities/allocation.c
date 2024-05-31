/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:31:51 by aheitz            #+#    #+#             */
/*   Updated: 2024/05/31 15:32:18 by aheitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//	* ---------- Memory allocation and initialization function ---------- *	//
//	? ---------- Allocates memory of size at specified address ---------- ?	//
//	? ------------------ Initializes each bits to '0' ------------------ ?	//
//	* ----------- On successful allocation, returns “SUCCESS” ----------- *	//
//	! ------------- If allocation fails, returns “FAILURE” ------------- !	//
int	set_allocation(void **target, const size_t size)
{
	*target = NULL;
	if (size)
	{
		*target = malloc(size);
		if (!*target)
			return (FAILURE);
		*target = memset(*target, 0, size);
	}
	return (SUCCESS);
}
