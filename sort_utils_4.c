/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:19:43 by merdal            #+#    #+#             */
/*   Updated: 2024/04/11 16:43:41 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_sml(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*top_b;

	current = *a;
	top_b = *b;
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

int	ft_check_if_big(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*top_b;

	current = *a;
	top_b = *b;
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
