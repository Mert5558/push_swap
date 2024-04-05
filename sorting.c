/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 16:46:49 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_stack(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->num == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) <= 5)
		ft_sort_small(a, &b);
	else
	{
		ft_rough_sort(a, &b);
		ft_last_sort(a, &b);
	}
}
