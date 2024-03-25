/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/25 15:30:11 by merdal           ###   ########.fr       */
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
	int chunk_size = 40;
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

	ft_pa(a, &b, 0);
	ft_pa(a, &b, 0);

	while (b != NULL)
	{
		ft_choose(a, &b);
		ft_sort_a(a, &b);

		// ft_choose_bottom(a, &b);
		// ft_sort_a(a, &b);
	}

	ft_smallest_to_top(a);
}
