/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:31:11 by merdal            #+#    #+#             */
/*   Updated: 2024/03/07 14:05:58 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_fake_chunks(void)
{
	int	*chunk;
	int	i = 0;
	int	value = 0;
	
	chunk = malloc(20 * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	
	while (i < 20)
	{
		chunk[i] = value;
		i++;
		value++;
	}
	return (chunk);
}
