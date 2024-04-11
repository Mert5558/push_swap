/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/04/11 16:16:14 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
