/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rough_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:18:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/11 17:15:45 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rough_sort(t_stack **a, t_stack **b)
{
	int	*chunk;
	int	chunk_size;
	int	i;

	chunk_size = 50;
	chunk = ft_make_chunk(a, chunk_size);
	i = 0;
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
		chunk = ft_make_chunk(a, chunk_size);
		i = 0;
	}
	free(chunk);
}
