/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/03/20 14:05:19 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_update_chunk(int *chunk, int chunk_size)
{
	int	i = 0;
	while (i < chunk_size)
	{
		chunk[i] += chunk_size;
		i++;
	}
	return (chunk);
}

int *ft_fake_chunks(int chunk_size)
{
	int	*chunk;
	int	i = 0;
	int	value = 1;
	
	chunk = malloc(chunk_size * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	
	while (i < chunk_size)
	{
		chunk[i] = value;
		i++;
		value++;
	}
	return (chunk);
}

int	*ft_create_chunk(t_stack **b, int chunk_size)
{
	int	*chunk;
	int	i = ft_lstsize(*b) - 1;
	t_stack *current = ft_lstlast(*b);
	
	chunk = malloc(chunk_size * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	
	while (i >= 0)
	{
		chunk[i] = current->num;
		current = current->prev;
		i--;
	}
	return (chunk);
}

int	*ft_update_chunk_2(t_stack **a, int *chunk, int chunk_size)
{
	int	i = ft_lstsize(*a) - 1;
	while (i >= 0)
	{
		chunk[i] -= chunk_size;
		if (chunk[i] == 0)
			break;
		i--;
	}
	return (chunk);
}
