/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/01 10:49:27 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_stack **a)
{
    if (!a || !*a)
    {
        return (1);
    }
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

long ft_find_second_smallest(t_stack *a, int smallest)
{
    int second_smallest = INT_MAX;

    while (a != NULL)
    {
        if (a->num < second_smallest && a->num > smallest)
        {
            second_smallest = a->num;
        }
        a = a->next;
    }
    return (second_smallest);
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
		while (index <= ft_lstsize(*a))
		{
			index++;
			moves++;
		}
	}
	return (moves);
}

void	ft_compare_moves(t_stack **a)
{
	int	moves_for_1;
	int	moves_for_2;
	int	index_smallest;
	int	index_second_smallest;

	index_smallest = ft_find_smallest(a);
	index_second_smallest = ft_find_second_smallest(*a, index_smallest);
	moves_for_1 = ft_calc_moves(a, index_smallest);
	moves_for_2 = ft_calc_moves(a, index_second_smallest);
	if (moves_for_1 - moves_for_2 < 0)
	{
		while (moves_for_1 != 0)
		{
			ft_ra(a, 0);
			moves_for_1--;
		}
	}
	else
	{
		while (moves_for_2 != 0)
		{
			ft_rra(a, 0);
			moves_for_2--;
		}
	}
}

int	ft_num_top(t_stack **stack)
{
	int	num_top;

	num_top = (*stack)->num;
	return (num_top);
}

void	ft_smallest_to_top(t_stack **b)
{
	while (ft_find_smallest(b) != 0)
	{
		ft_rb(b, 0);
	}
}

void	ft_check_push(t_stack **a, t_stack **b)
{
	int	top_a;
	int	top_b;

	top_a = ft_num_top(a);
	if (b)
		top_b = ft_num_top(b);
	else
		top_b = - 1;
	if (top_a - top_b > 0)
		ft_pb(a, b, 0);
	else
	{
		ft_smallest_to_top(b);
		ft_pb(a, b, 0);
	}
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	ft_compare_moves(a);
	ft_check_push(a, &b);
}
