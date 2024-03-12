/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/12 13:40:47 by merdal           ###   ########.fr       */
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
	ft_biggest_to_top(&b);
	ft_sort_b(a, &b);
	chunk = ft_update_chunk(chunk);
	//push_to_a()
}
