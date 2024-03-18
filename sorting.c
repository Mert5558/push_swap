/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/18 12:57:15 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a)
{
	t_stack	*b = NULL;
	int *chunk;

	chunk = ft_fake_chunks();

	ft_scan_move(a, chunk);
	ft_pb(&b, a, 0);
	ft_scan_move(a, chunk);
	ft_pb(&b, a, 0);
	
	while (a != NULL)
	{
		ft_scan_move(a, chunk);
		ft_sort_b(a, &b);
	}
	
	// 21 2 24 25 1 11 16 18 6 4 7 12 19 13 10 3 5 17 14 15 8 9 22 23
}
