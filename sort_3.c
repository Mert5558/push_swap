/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:29:44 by merdal            #+#    #+#             */
/*   Updated: 2024/04/01 13:25:11 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_3(t_stack **a)
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