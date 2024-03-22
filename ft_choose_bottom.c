/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:16:14 by merdal            #+#    #+#             */
/*   Updated: 2024/03/22 17:31:02 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_options_bottom(t_stack **a, t_stack **b, int size_options)
{
	t_stack	*current = ft_lstlast(*b);
	int	*options;
	int	i = 0;

	options = (int *)malloc(sizeof(int) * size_options);
	if (!options)
		return (NULL);

	while (i < size_options)
	{
		options[i] = ft_moves_options(a, current) + i + 1;
		i++;
		current = current->prev;
	}
	return (options);
}

void	ft_choose_bottom(t_stack **a, t_stack **b)
{
	int	*options;
	int	less_moves;
	int	temp;
	int	size_options = 15;


	if (ft_lstsize(*b) < size_options)
		size_options = ft_lstsize(*b);
	
	options = ft_get_options_bottom(a, b, size_options);
	//print_array(options, size_options);
	
	if (!options)
		ft_error();
	
	temp = ft_find_less_moves(options, size_options);
	less_moves = ft_lstsize(*b) + temp - 1;
	//printf("less_moves: %d\n", less_moves);

	ft_index_to_top(b, less_moves);

	free(options);
	// 46 63 2 13 40 64 35 80 49 36 95 3 60 34 17 68 70 73 52 11 38 61 76 59 32 42 54 27 90 99 44 67 78 45 25 23 62 100 12 81 89 53 87 98 15 18 43 75 33 29 82 91 31 92 66 5 71 69 56 47 72 16 21 41 74 94 26 7 86 85 57 84 37 65 58 8 93 4 83 96 77 50 55 14 6 19 88 79 10 39 28 24 9 48 30 22 51 97 20 1
}