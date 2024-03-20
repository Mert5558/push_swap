/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/20 16:31:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a)
{
	t_stack	*b = NULL;
	int *chunk;
	int	*chunk_2;
	int chunk_size = 30;
	int chunks_size_2 = 15;
	int i = 0;

	chunk = ft_fake_chunks(chunk_size);
	chunk_2 = ft_create_chunk(&b, chunk_size);
	
	while (*a != NULL)
	{
		while (i < chunk_size && *a != NULL)
		{
			ft_scan_move(a, chunk, chunk_size);
			ft_pb(&b, a, 0);
			i++;
		}
		chunk = ft_update_chunk(chunk, chunk_size);
		i = 0;
	}
	
	ft_scan_move(&b, chunk_2, chunks_size_2);
	ft_pa(a, &b, 0);
	i++;
	ft_scan_move(&b, chunk_2, chunks_size_2);
	ft_pa(a, &b, 0);
	i++;
	while (b != NULL)
	{
		while (i < chunks_size_2 && b != NULL)
		{
			ft_scan_move(&b, chunk_2, chunks_size_2);
			ft_sort_a(a, &b);
			i++;
		}
		chunk_2 = ft_update_chunk_2(a, chunk_2, chunks_size_2);
		i = 0;
	}
}
