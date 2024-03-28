/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:43:36 by merdal            #+#    #+#             */
/*   Updated: 2024/03/28 16:25:32 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_moves_options(t_stack **a, t_stack *value)
{
	int	moves  = 0;
	
	if (ft_check_if_smallest2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_biggest2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_smallest2(a, value) == 1 && ft_check_if_biggest2(a, value) == 1)
	{
		moves = ft_mid_to_top_moves(a, value);
		return (moves);
	}
	return (moves);
}

int ft_is_chunk_finished(t_stack **b, int *chunk_2)
{
	t_stack *current = *b;
	
	while (current != NULL)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0); // Number in the chunk found
		current = current->next;
	}
	return (1); // No numbers in the chunk found
}

int ft_finished_top(t_stack **b, int *chunk_2)
{
	t_stack *current = *b;
	int middle = 0;
	int i = 0;

	middle = 10;
	if (ft_lstsize(*b) <= 10)
		middle = ft_lstsize(*b);
	while (i < middle)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0); // Number in the chunk found
		current = current->next;
		i++;
	}
	return (1); // No numbers in the chunk found
}

int	ft_finished_bottom(t_stack **b, int *chunk_2)
{
	t_stack *current = ft_lstlast(*b);
	int	middle = 0;
	int i = 0;

	middle = 10;
	if (ft_lstsize(*b) <= 10)
		middle = ft_lstsize(*b);
	while (i < middle)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0); // Number in the chunk found
		current = current->prev;
		i++;
	}
	return (1); // No numbers in the chunk found
}
