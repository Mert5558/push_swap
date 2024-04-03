/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rough_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:18:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/03 16:29:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rough_sort(t_stack **a, t_stack **b)
{
	int *chunk;
	int chunk_size = 5;
	int i = 0;
	
	chunk = ft_make_chunk(a, chunk_size);
	print_array(chunk, chunk_size);
	
	while (*a != NULL)
	{
		while (i < chunk_size && *a != NULL)
		{
			ft_scan_move(a, chunk, chunk_size);
			ft_pb(b, a, 0);
			i++;
		}
		if (ft_lstsize(*a) < chunk_size)
			chunk_size = ft_lstsize(*a);

		chunk = ft_update_chunk(chunk, chunk_size);
		printf("update");
		print_array(chunk, chunk_size);
		i = 0;
	}
	free(chunk);
}
