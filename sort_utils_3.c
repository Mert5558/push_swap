/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:55:56 by merdal            #+#    #+#             */
/*   Updated: 2024/03/20 16:11:03 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallest_to_top(t_stack **a)
{
	int	index_smallest;
	int	moves;
	
	index_smallest = ft_find_smallest(a);
	moves = ft_calc_moves(a, index_smallest);
	ft_calc_which_command(a, index_smallest, moves);
}

void	ft_biggest_to_top(t_stack **a)
{
	int	index_biggest;
	int	moves;
	
	index_biggest = ft_find_biggest(a);
	moves = ft_calc_moves(a, index_biggest);
	ft_calc_which_command(a, index_biggest, moves);
}

void	ft_mid_to_top(t_stack **a, t_stack **b)
{
	int	index_mid;
	int	moves;

	index_mid = ft_find_mid(a, b);
	moves = ft_calc_moves(a, index_mid);
	ft_calc_which_command(a, index_mid, moves);
}
