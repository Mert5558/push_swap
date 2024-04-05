/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:26 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 16:45:11 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_biggest(t_stack **stack)
{
	int		max_index;
	int		biggest_value;
	int		index;
	t_stack	*current;

	if (!stack || !*stack)
		ft_error();
	max_index = 0;
	biggest_value = (*stack)->num;
	index = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->num > biggest_value)
		{
			biggest_value = current->num;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

int	ft_find_smallest(t_stack **a)
{
	int		min_index;
	long	smallest_value;
	int		index;
	t_stack	*current;

	if (!a || !*a)
		ft_error();
	min_index = 0;
	smallest_value = (*a)->num;
	index = 0;
	current = *a;
	while (current != NULL)
	{
		if (current->num < smallest_value)
		{
			smallest_value = current->num;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

int	ft_find_mid(t_stack **a, t_stack **b)
{
	int		index;
	t_stack	*top_b;
	t_stack	*current;
	int		nearest_big;
	int		nearest_index;

	index = 0;
	top_b = *b;
	current = *a;
	nearest_big = INT_MAX;
	nearest_index = -1;
	while (current != NULL)
	{
		if (current->num > top_b->num && current->num < nearest_big)
		{
			nearest_big = current->num;
			nearest_index = index;
		}
		current = current->next;
		index++;
	}
	return (nearest_index);
}
