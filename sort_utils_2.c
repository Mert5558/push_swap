/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:51:54 by merdal            #+#    #+#             */
/*   Updated: 2024/04/04 16:31:52 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_moves(t_stack **a, int index)
{
	int	moves;

	moves = 0;
	if (index <= ft_lstsize(*a) / 2)
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
	
	if (index <= ft_lstsize(*a) / 2)
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

int	ft_smallest_value(t_stack **a)
{
	t_stack	*current = *a;
	int		smallest = current->num;

	while (current != NULL)
	{
		if (current->num < smallest)
			smallest = current->num;
		current = current->next;
	}
	return (smallest);
}

int ft_next_value(t_stack **a, int value)
{
	t_stack	*current = *a;
	int		next_value = INT_MAX;

	while (current != NULL)
    {
		if (current->num > value && current->num < next_value)
		{
			next_value = current->num;
		}
		current = current->next;
	}
	return (next_value);
}