/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/04 15:24:40 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_chunks(t_stack **a)
{
	int	stack_len;
	int	chunks_amout;
	int	i = 0;
	int	j = 0;
	int	**chunks;

	stack_len = ft_lstsize(a);
	chunks_amout = stack_len / 20;
	chunks[chunks_amout][20];
	if (stack_len % 20 != 0)
		chunks_amout++;
	while (i < chunks_amout)
	{
		while (j < 20)
		{
			chunks[i][j] = i * 20 +j;
		}
	}
}

int	ft_find_smallest(t_stack **a) //change
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

int ft_find_second_smallest(t_stack **a) //change
{
    if (!a || !*a)
        ft_error();

    int smallest_index = ft_find_smallest(a);
    int second_smallest_index = -1;
    int index = 0;
    t_stack *current = *a;
    long smallest_value = INT_MAX;
    long second_smallest_value = INT_MAX;

    while (current != NULL)
    {
        if (index == smallest_index) {
            smallest_value = current->num;
        }
        else if (current->num < second_smallest_value) {
            second_smallest_value = current->num;
            second_smallest_index = index;
        }
        current = current->next;
        index++;
    }
    return (second_smallest_index);
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

void	ft_compare_moves(t_stack **a)
{
	int	moves_for_1;
	int	moves_for_2;
	int	index_smallest;
	int	index_second_smallest;

	index_smallest = ft_find_smallest(a);
	index_second_smallest = ft_find_second_smallest(a);
	moves_for_1 = ft_calc_moves(a, index_smallest);
	moves_for_2 = ft_calc_moves(a, index_second_smallest);
	if (moves_for_1 < moves_for_2)
	{
		ft_calc_which_command(a, index_smallest, moves_for_1);
	}
	else
	{
		ft_calc_which_command(a, index_second_smallest, moves_for_2);
	}
}

void	ft_sort(t_stack **a)
{
	t_stack	**b;

	b = NULL;
	ft_compare_moves(a);
	ft_check_push(a, b);
}
