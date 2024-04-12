/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:53:52 by merdal            #+#    #+#             */
/*   Updated: 2024/04/12 16:11:55 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_options(t_stack **a, t_stack **b, int size_options)
{
	t_stack	*current;
	int		*options;
	int		i;

	current = *b;
	i = 0;
	options = (int *)malloc(sizeof(int) * size_options);
	if (!options)
		return (NULL);
	while (i < size_options)
	{
		options[i] = ft_moves_options(a, current) + i;
		i++;
		current = current->next;
	}
	return (options);
}

int	ft_check_stack(t_stack **b, int *chunk_2, int size_options)
{
	t_stack	*current;
	int		count;
	int		i;

	current = *b;
	i = 0;
	count = 0;
	while (i < size_options)
	{
		if (ft_is_in_chunk(chunk_2, current) == 1)
		{
			count++;
		}
		else if (ft_is_in_chunk(chunk_2, current) == 0)
			break ;
		current = current->next;
		i++;
	}
	return (count);
}

int	ft_choose(t_stack **a, t_stack **b, int *chunk_2, int chunk_size)
{
	int	*options;
	int	less_moves;
	int	size_options;

	size_options = chunk_size;
	if (ft_lstsize(*b) < size_options)
		size_options = ft_lstsize(*b);
	size_options = ft_check_stack(b, chunk_2, size_options);
	options = ft_get_options(a, b, size_options);
	if (!options)
		ft_error();
	less_moves = ft_find_less_moves(options, size_options);
	ft_index_to_top(b, less_moves);
	free(options);
	return (less_moves);
}
