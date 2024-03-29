/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/28 16:58:44 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void returnArrayValues(int arr[], int size) {
    printf("Array values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
	int *chunk;
	int	*chunk_2;
	int chunk_size = 50;
	int	chunk_2_size = 50;
	int i = 0;

	chunk = ft_fake_chunks(chunk_size);
	
	while (*a != NULL)
	{
		while (i < chunk_size && *a != NULL)
		{
			ft_scan_move(a, chunk, chunk_size);
			ft_pb(&b, a, 0);
			i++;
		}
		chunk = ft_update_chunk(chunk, chunk_size);
		i = 0;
	}

	chunk_2 = ft_create_chunk(&b, chunk_2_size);
	//print_array(chunk_2, chunk_2_size);

	ft_pa(a, &b, 0);
	i++;
	ft_pa(a, &b, 0);
	i++;

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
		chunk_2 = ft_update_chunk_2(chunk_2, chunk_2_size);
		//print_array(chunk_2, chunk_2_size);
	}

	ft_smallest_to_top(a);
}
