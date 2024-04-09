/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/04/09 17:42:00 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_lstsize(*b) < chunk_size)
		chunk_size = ft_lstsize(*b);
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

int	ft_biggest_value(t_stack **b)
{
	t_stack	*current;
	int		biggest;

	current = *b;
	biggest = current->num;
	while (current != NULL)
	{
		if (current->num > biggest)
			biggest = current->num;
		current = current->next;
	}
	return (biggest);
}

int ft_next_smallest_value(t_stack **b, int value)
{
    t_stack *current;
    int next_smallest_value = INT_MIN;

    current = *b;
    while (current != NULL)
    {
        if (current->num < value && current->num > next_smallest_value)
        {
            next_smallest_value = current->num;
        }
        current = current->next;
    }
    return (next_smallest_value);
}


int	*ft_make_chunk_2(t_stack **b, int chunk_size)
{
	t_stack	*current;
	int 	*chunk_2;
	int		value;
	int		i;
	
	current = *b;
	i = 0;
	if (*b == NULL || b == NULL || chunk_size == 0)
		return (NULL);
	if (ft_lstsize(*b) < chunk_size)
		chunk_size = ft_lstsize(*b);
	chunk_2 = malloc(chunk_size * sizeof(int));
	if (chunk_2 == NULL)
		return (NULL);
	
	value = ft_biggest_value(b);
	while (i < chunk_size && current != NULL)
	{
		chunk_2[i] = value;
		value = ft_next_smallest_value(b, value);
		i++;
		current = current->next;
	}
	return (chunk_2);
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
