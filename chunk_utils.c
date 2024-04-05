/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 16:03:09 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_update_chunk(int *chunk, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		chunk[i] += chunk_size;
		i++;
	}
	return (chunk);
}

int	*ft_make_chunk(t_stack **a, int chunk_size)
{
	t_stack	*current;
	int		*chunk;
	int		value;
	int		i;

	current = *a;
	i = 0;
	if (chunk_size == 0)
		return (NULL);
	chunk = malloc(chunk_size * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	value = ft_smallest_value(a);
	while (i < chunk_size && current != NULL)
	{
		chunk[i] = value;
		value = ft_next_value(a, value);
		i++;
		current = current->next;
	}
	return (chunk);
}

int	*ft_create_chunk(t_stack **b, int chunk_size)
{
	t_stack	*current;
	int		*chunk;
	int		value;
	int		i;

	current = *b;
	i = 0;
	if (chunk_size == 0)
		return (NULL);
	chunk = malloc(chunk_size * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	while (chunk_size != 0 && current != NULL)
	{
		value = current->num;
		chunk[i] = value;
		current = current->next;
		i++;
		chunk_size--;
	}
	return (chunk);
}

int	*ft_update_chunk_2(int *chunk, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		chunk[i] -= chunk_size;
		i++;
	}
	return (chunk);
}

int	ft_is_in_chunk(int *chunk_2, t_stack *current)
{
	int	i;

	i = 0;
	while (chunk_2[i] != '\0')
	{
		if (chunk_2[i] == current->num)
			return (1);
		i++;
	}
	return (0);
}
