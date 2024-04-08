/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:22:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/08 16:09:41 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_sort(t_stack **a, t_stack **b)
{
	int	*chunk_2 = NULL;
	int	chunk_2_size;

	chunk_2_size = 10;
	chunk_2 = ft_make_chunk_2(b, chunk_2, chunk_2_size);
	print_array(chunk_2, chunk_2_size);
	ft_pa(a, b, 0);
	ft_pa(a, b, 0);
	while (*b != NULL)
	{
		while (ft_is_chunk_finished(b, chunk_2) == 0)
		{
			if (ft_finished_top(b, chunk_2) == 0)
				ft_choose(a, b, chunk_2, chunk_2_size);
			else if (ft_finished_bottom(b, chunk_2) == 0)
				ft_choose_bottom(a, b, chunk_2, chunk_2_size);
			ft_sort_a(a, b);
		}
		chunk_2 = ft_make_chunk_2(b, chunk_2, chunk_2_size);
		print_array(chunk_2, chunk_2_size);
	}
	free(chunk_2);
	ft_smallest_to_top(a);
}
// 84 41 22 35 88 29 3 62 6 81 48 63 99 97 64 36 38 52 74 39 20 49 89 93 17 32 15 94 7 58 65 80 78 75 27 8 19 9 85 67 53 14 33 68 37 5 57 56 21 43 44 77 28 54 86 95 0 26 98 11 40 18 71 55 50 96 2 76 24 92 46 13 59 69 10 47 25 66 16 30 42 82 31 87 34 61 1 51 45 73 83 72 90 79 12 4 23 91 60 70 