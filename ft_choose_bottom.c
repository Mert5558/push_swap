/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:16:14 by merdal            #+#    #+#             */
/*   Updated: 2024/03/26 12:00:14 by merdal           ###   ########.fr       */
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

int	ft_is_in_chunk_2(t_stack **b, int *chunk_2, int size_options)
{
	int	i = 0;
	int	count = 0;
	t_stack	*current = ft_lstlast(*b);
	
	while (count < size_options)
	{
		while (chunk_2[i] != '\0')
		{
			if (current->num == chunk_2[i])
				count++;
			i++;
		}
		current = current->prev;
		i = 0;
	}
	return (count);
}

void	ft_choose_bottom(t_stack **a, t_stack **b, int *chunk_2)
{
	int	*options;
	int	less_moves;
	int	temp;
	int	size_options = 15;


	if (ft_lstsize(*b) < size_options)
		size_options = ft_lstsize(*b);
	
	size_options = ft_is_in_chunk_2(b, chunk_2, size_options);

	options = ft_get_options_bottom(a, b, size_options);
	
	if (!options)
		ft_error();
	
	temp = ft_find_less_moves(options, size_options);
	less_moves = ft_lstsize(*b) - temp - 1;

	ft_index_to_top(b, less_moves);

	free(options);
}
