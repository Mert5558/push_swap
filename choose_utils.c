/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:16:56 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 15:57:28 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest_to_top_moves(t_stack **a)
{
	int	index_biggest;
	int	moves;

	index_biggest = ft_find_biggest(a);
	moves = ft_calc_moves(a, index_biggest);
	return (moves);
}

int	ft_smallest_to_top_moves(t_stack **a)
{
	int	index_smallest;
	int	moves;

	index_smallest = ft_find_smallest(a);
	moves = ft_calc_moves(a, index_smallest);
	return (moves);
}

int	ft_mid_to_top_moves(t_stack **a, t_stack *value)
{
	int	index_mid;
	int	moves;

	index_mid = ft_find_mid(a, &value);
	moves = ft_calc_moves(a, index_mid);
	return (moves);
}

int	ft_check_if_smallest2(t_stack **a, t_stack *value)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		if (value->num >= current->num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_check_if_biggest2(t_stack **a, t_stack *value)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		if (value->num <= current->num)
			return (1);
		current = current->next;
	}
	return (0);
}
