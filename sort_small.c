/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:30:08 by merdal            #+#    #+#             */
/*   Updated: 2024/04/11 16:32:19 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **a)
{
	if (ft_find_smallest(a) == 0)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_find_biggest(a) == 0)
	{
		ft_ra(a, 0);
		if (ft_checkifsorted(*a) == 0)
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_biggest(a) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

void	ft_sort_4(t_stack **a, t_stack **b)
{
	ft_pb(b, a, 0);
	if (!ft_checkifsorted(*a))
		ft_sort_3(a);
	ft_sort_a(a, b);
	ft_smallest_to_top(a);
}

void	ft_sort_5(t_stack **a, t_stack **b)
{
	ft_pb(b, a, 0);
	ft_pb(b, a, 0);
	if (!ft_checkifsorted(*a))
		ft_sort_3(a);
	ft_sort_a(a, b);
	ft_sort_a(a, b);
	ft_smallest_to_top(a);
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		ft_sa(a, 0);
	else if (ft_lstsize(*a) == 3)
		ft_sort_3(a);
	else if (ft_lstsize(*a) == 4)
		ft_sort_4(a, b);
	else if (ft_lstsize(*a) == 5)
		ft_sort_5(a, b);
}
