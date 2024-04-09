/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:22:39 by merdal            #+#    #+#             */
/*   Updated: 2024/04/09 16:31:20 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_sort(t_stack **a, t_stack **b)
{
	int	*chunk_2 = NULL;
	int	chunk_2_size;

	chunk_2_size = 50;
	chunk_2 = ft_make_chunk_2(b, chunk_2_size);
	//print_array(chunk_2, chunk_2_size);
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
		chunk_2 = ft_make_chunk_2(b, chunk_2_size);
		//print_array(chunk_2, chunk_2_size);
	}
	free(chunk_2);
	ft_smallest_to_top(a);
}
// 96 25 88 93 90 10 73 43 18 3 92 13 98 33 29 15 2 70 49 71 16 62 42 77 67 4 69 6 37 35 74 86 51 99 38 58 81 27 47 22 84 45 5 54 8 64 34 1 19 94 85 59 11 95 78 80 36 83 46 89 30 41 56 14 7 75 17 76 21 39 48 24 44 40 50 91 20 31 55 61 72 66 82 12 97 26 79 52 28 23 53 32 65 68 57 0 87 60 63 9 