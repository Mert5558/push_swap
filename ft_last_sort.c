/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:22:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/12 17:12:11 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void	ft_last_sort(t_stack **a, t_stack **b)
{
	int	*chunk_2;
	int	chunk_2_size;

	chunk_2 = NULL;
	chunk_2_size = 50;
	chunk_2 = ft_make_chunk_2(b, chunk_2_size);
	ft_pa(a, b, 0);
	ft_pa(a, b, 0);
	while (*b != NULL)
	{
		while (ft_is_chunk_finished(b, chunk_2) == 0)
		{
			if (ft_finished_top(b, chunk_2) == 0)
				ft_choose(a, b, chunk_2, chunk_2_size);
			else if (ft_finished_bottom(b, chunk_2) == 0)
				ft_choose_bot(a, b, chunk_2, chunk_2_size);
			ft_sort_a(a, b);
		}
		chunk_2 = ft_make_chunk_2(b, chunk_2_size);
	}
	free(chunk_2);
	ft_smallest_to_top(a);
}
