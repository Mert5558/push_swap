/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rough_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:18:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/01 13:26:10 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rough_sort(t_stack **a, t_stack **b)
{
	int *chunk;
	int chunk_size = 50;
	int i = 0;

	chunk = ft_fake_chunks(chunk_size);
	
	while (*a != NULL)
	{
		while (i < chunk_size && *a != NULL)
		{
			ft_scan_move(a, chunk, chunk_size);
			ft_pb(b, a, 0);
			i++;
		}
		chunk = ft_update_chunk(chunk, chunk_size);
		i = 0;
	}
}