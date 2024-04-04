/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:26 by merdal            #+#    #+#             */
/*   Updated: 2024/04/04 16:22:32 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_biggest(t_stack **stack)
{
	if (!stack || !*stack)
		ft_error();
	int	max_index = 0;
	int	biggest_value = (*stack)->num;
	int	index = 0;
	t_stack	*current = *stack;

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
    if (!a || !*a)
    	ft_error();
    int min_index = 0;
    long smallest_value = (*a)->num;
    int index = 0;
    t_stack *current = *a;

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
	int	index = 0;
	t_stack	*top_b = *b;
	t_stack	*current = *a;
	int	nearest_big = INT_MAX;
	int	nearest_index = - 1;

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
