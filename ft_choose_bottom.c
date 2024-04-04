/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:16:14 by merdal            #+#    #+#             */
/*   Updated: 2024/04/04 14:33:02 by merdal           ###   ########.fr       */
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

int ft_check_stack_2(t_stack **b, int *chunk_2, int size_options)
{
	t_stack	*current = ft_lstlast(*b);
	int	count = 0;
	int i = 0;

	while (i < size_options)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
		{
			count++;
		}
		else if (ft_is_in_chunk(chunk_2, current) == 0)
			break;
		current = current->prev;
		i++;
	}
	//printf("count bot: %d\n", count);
	return (count);
}

int	ft_choose_bottom(t_stack **a, t_stack **b, int *chunk_2)
{
	int	*options;
	int	less_moves;
	int	temp;
	int	size_options = 50;


	if (ft_lstsize(*b) < size_options)
		size_options = ft_lstsize(*b);
	
	size_options = ft_check_stack_2(b, chunk_2, size_options);

	options = ft_get_options_bottom(a, b, size_options);
	
	if (!options)
		ft_error();
	
	temp = ft_find_less_moves(options, size_options);
	less_moves = ft_lstsize(*b) - temp - 1;

	ft_index_to_top(b, less_moves);

	free(options);
	return (less_moves);
}
