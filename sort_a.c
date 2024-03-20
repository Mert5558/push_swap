/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:23 by merdal            #+#    #+#             */
/*   Updated: 2024/03/20 15:47:07 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_stack **a, t_stack **b)
{
	if (ft_check_if_biggest(a, b) == 0)
	{
		ft_smallest_to_top(a);
		ft_pa(a, b, 0);
	}
	else if (ft_check_if_smallest(a, b) == 0)
	{
		ft_smallest_to_top(a);
		ft_pa(a, b, 0);
	}
	else if ((ft_check_if_smallest(a, b) == 1) && (ft_check_if_biggest(a, b) == 1))
	{
		ft_mid_to_top(a, b);
		ft_pa(a, b, 0);
	}
}
