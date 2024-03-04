/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:13:49 by merdal            #+#    #+#             */
/*   Updated: 2024/03/04 13:14:48 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_top(t_stack **stack)
{
	int	num_top;

	num_top = (*stack)->num;
	return (num_top);
}

void	ft_smallest_to_top(t_stack **b)
{
	while (ft_find_smallest(b) != 0)
	{
		ft_rb(b, 0);
	}
}

void	ft_check_push(t_stack **a, t_stack **b)
{
	int	top_a;
	int	top_b;

	if (!a || !*a)
		return ;
	
	top_a = ft_num_top(a);
	top_b = INT_MAX;
	if (b && *b)
		top_b = ft_num_top(b);
	if (!b || ! *b || top_a < top_b)
		ft_pb(a, b, 0);
	else
	{
		ft_smallest_to_top(b);
		ft_pb(a, b, 0);
	}
}
