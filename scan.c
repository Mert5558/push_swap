/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:10:36 by merdal            #+#    #+#             */
/*   Updated: 2024/03/19 14:43:08 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_last_stack(t_stack **a)
{
	t_stack	*current = *a;

	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	ft_scan_top(t_stack **a, int *chunk, int chunk_size)
{
	int index_chunk = 0;
	int	index_stack = 0;
	t_stack *current = *a;

	while (current != NULL)
	{
		index_chunk = 0;
		while (index_chunk < chunk_size)
		{
			if (current->num == chunk[index_chunk])
			{
				return (index_stack);
			}
			index_chunk++;
		}
		current = current->next;
		index_stack++;
	}
	return (0);
}

int	ft_scan_bottom(t_stack **a, int *chunk, int chunk_size)
{
	int index_chunk = 0;
	int	index_stack = ft_lstsize(*a) - 1;
	t_stack *current = ft_get_last_stack(a);

	while (current != NULL)
	{
		index_chunk = 0;
		while (index_chunk < chunk_size)
		{
			if (current->num == chunk[index_chunk])
			{
				return (index_stack);
			}
			index_chunk++;
		}
		current = current->prev;
		index_stack--;
	}
	return (0);
}

void	ft_scan_move(t_stack **a, int *chunk, int chunk_size)
{
	int index_1;
	int	index_2;
	int	moves_1;
	int	moves_2;
	
	index_1 = ft_scan_top(a, chunk, chunk_size);
	index_2 = ft_scan_bottom(a, chunk, chunk_size);
	moves_1 = ft_calc_moves(a, index_1);
	moves_2 = ft_calc_moves(a, index_2);
	if (moves_1 < moves_2)
	{
		ft_calc_which_command(a, index_1, moves_1);
	}
	else
	{
		ft_calc_which_command(a, index_2, moves_2);
	}
}
