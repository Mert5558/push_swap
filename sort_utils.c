/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:26 by merdal            #+#    #+#             */
/*   Updated: 2024/03/12 14:24:39 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_biggest(t_stack **stack)
{
	if (!stack || !*stack)
		ft_error();
	int	max_index = 0;
	int	biggest_value = (*stack)->num;
	int	index = 0;
	t_stack	*current = *stack;

	while (current != NULL)
	{
		if (current->num > biggest_value)
        {
            biggest_value = current->num;
            max_index = index;
        }
        current = current->next;
        index++;
	}
	return (max_index);
}

int	ft_find_smallest(t_stack **a)
{
    if (!a || !*a)
    	ft_error();
    int min_index = 0;
    long smallest_value = (*a)->num;
    int index = 0;
    t_stack *current = *a;

    while (current != NULL)
    {
        if (current->num < smallest_value)
        {
            smallest_value = current->num;
            min_index = index;
        }
        current = current->next;
        index++;
    }
	return (min_index);
}

int	ft_find_mid(t_stack **a, t_stack **b)
{
	int	index = 0;
	t_stack	*top_a = *a;
	t_stack	*current = *b;

	while (current != NULL)
	{
		if (top_a->num > current->num)
		{
			break;
		}
		current = current->next;
		index++;
	}
	return (index);
}

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

void	ft_calc_which_command_b(t_stack **b, int	index, int moves)
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
