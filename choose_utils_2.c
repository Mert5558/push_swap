/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:43:36 by merdal            #+#    #+#             */
/*   Updated: 2024/04/12 16:35:36 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_moves_options(t_stack **a, t_stack *value)
{
	int	moves;

	moves = 0;
	if (ft_check_if_sml2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_big2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_sml2(a, value) == 1 && ft_check_if_big2(a, value) == 1)
	{
		moves = ft_mid_to_top_moves(a, value);
		return (moves);
	}
	return (moves);
}

int	ft_is_chunk_finished(t_stack **b, int *chunk_2)
{
	t_stack	*current;

	if (chunk_2 == NULL)
		return (1);
	current = *b;
	while (current != NULL)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_finished_top(t_stack **b, int *chunk_2)
{
	t_stack	*current;
	int		middle;
	int		i;

	current = *b;
	middle = 50;
	i = 0;
	if (ft_lstsize(*b) <= middle)
		middle = ft_lstsize(*b);
	while (i < middle)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	ft_finished_bottom(t_stack **b, int *chunk_2)
{
	t_stack	*current;
	int		middle;
	int		i;

	current = ft_lstlast(*b);
	middle = 50;
	i = 0;
	if (ft_lstsize(*b) <= middle)
		middle = ft_lstsize(*b);
	while (i < middle)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
			return (0);
		current = current->prev;
		i++;
	}
	return (1);
}
