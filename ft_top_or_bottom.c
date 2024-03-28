/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_or_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:45:42 by merdal            #+#    #+#             */
/*   Updated: 2024/03/27 13:52:18 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_top_or_bottom(t_stack **b, int index1, int index2)
{
	int moves1;
	int moves2;
	int index_less_moves;

	moves1 = ft_calc_moves(b, index1);
	moves2 = ft_calc_moves(b, index2);

	if (moves1 < moves2)
		index_less_moves = index1;
	else
		index_less_moves = index2;

	ft_index_to_top(b, index_less_moves);
}