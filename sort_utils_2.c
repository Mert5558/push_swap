/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:51:54 by merdal            #+#    #+#             */
/*   Updated: 2024/03/25 12:05:36 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_moves(t_stack **a, int index)
{
	int	moves;

	moves = 0;
	if (index < ft_lstsize(*a) / 2)
	{
		while (index != 0)
		{
			index--;
			moves++;
		}
	}
	else
	{
		while (index < ft_lstsize(*a))
		{
			index++;
			moves++;
		}
	}
	return (moves);
}

void	ft_calc_which_command(t_stack **a, int	index, int moves)
{
	int	i = 0;
	
	if (index < ft_lstsize(*a) / 2)
	{
		while (i < moves)
		{
			ft_ra(a, 0);
			i++;
		}
	}
	else
	{
		while (i < moves)
		{
			ft_rra(a, 0);
			i++;
		}
	}
}

void	ft_calc_which_command_b(t_stack **b, int index, int moves)
{
	int	i = 0;
	
	if (index < ft_lstsize(*b) / 2)
	{
		while (i < moves)
		{
			ft_rb(b, 0);
			i++;
		}
	}
	else
	{
		while (i < moves)
		{
			ft_rrb(b, 0);
			i++;
		}
	}
}