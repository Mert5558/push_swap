/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/04/01 14:16:30 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_in_stack(t_stack *stack, int num)
{
    while (stack != NULL)
    {
        if (stack->num == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b = NULL;
	int	*chunk_2;
	int	chunk_2_size = 50;

	ft_rough_sort(a, &b);

	chunk_2 = ft_create_chunk(&b, chunk_2_size);
	// //print_array(chunk_2, chunk_2_size);

	ft_pa(a, &b, 0);
	ft_pa(a, &b, 0);

	//ft_last_sort(a, &b);
	
	while (b != NULL)
	{
		while (ft_is_chunk_finished(&b, chunk_2) == 0)
		{
			if (ft_finished_top(&b, chunk_2) == 0)
				ft_choose(a, &b, chunk_2);

			else if (ft_finished_bottom(&b, chunk_2) == 0)
				ft_choose_bottom(a, &b, chunk_2);

			ft_sort_a(a, &b);
		}
		chunk_2 = ft_create_chunk(&b, chunk_2_size);
		//print_array(chunk_2, chunk_2_size);
		// ft_choose(a, &b, chunk_2);
		// ft_sort_a(a, &b);
	}
	ft_smallest_to_top(a);
}
