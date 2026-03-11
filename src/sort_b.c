/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:19:43 by merdal            #+#    #+#             */
/*   Updated: 2024/04/10 14:41:01 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_smallest(t_stack **a, t_stack **b)
{
	t_stack	*current = *a;
	t_stack	*top_b = *b;

	while (current != NULL)
	{
		if (current->num == INT_MIN)
			return (1);
		if (top_b->num >= current->num)
			return (1);
		current = current->next;
	}
	return (0);
}

int ft_check_if_biggest(t_stack **a, t_stack **b)
{
    t_stack *current = *a;
    t_stack *top_b = *b;

    while (current != NULL)
    {
        if (current->num == INT_MAX)
			return (1);
		if (top_b->num <= current->num)
            return (1);
        current = current->next;
    }
    return (0);
}

void	ft_sort_b(t_stack **a, t_stack **b)
{
	if (ft_check_if_biggest(b, a) == 0)
	{
		//write(1, "big\n", 4);
		ft_biggest_to_top(b);
		ft_pb(b, a, 0);
	}
	else if (ft_check_if_smallest(b, a) == 0)
	{
		//write(1, "sml\n", 4);
		ft_biggest_to_top(b);
		ft_pb(b, a, 0);
	}
	else if ((ft_check_if_biggest(b, a) == 1) && (ft_check_if_smallest(b, a) == 1))
	{
		//write(1, "mid\n", 4);
		ft_mid_to_top(a, b);
		ft_pb(b, a, 0);
	}
}
