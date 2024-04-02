/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/03/29 15:07:54 by merdal           ###   ########.fr       */
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

// int	*ft_create_chunk(t_stack **b, int chunk_size)
// {
// 	int	*chunk;
// 	int	value = ft_lstsize(*b);
// 	int	i = 0;
	
// 	chunk = malloc(chunk_size * sizeof(int));
// 	if (chunk == NULL)
// 		return (NULL);
	
// 	while (value >= 0 && chunk_size != 0)
// 	{
// 		chunk[i] = value;
// 		i++;
// 		value--;
// 		chunk_size--;
// 	}
// 	return (chunk);
// }

int	*ft_create_chunk(t_stack **b, int chunk_size)
{
	int	*chunk;
	int	i = 0;
	int	value;
	t_stack	*current = *b;
	
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
	int	i = 0;
	while (i < chunk_size)
	{
		chunk[i] -= chunk_size;
		i++;
	}
	return (chunk);
}

int ft_is_in_chunk(int *chunk_2, t_stack *current)
{
   int	i = 0;

   while (chunk_2[i] != '\0')
   {
	   if (chunk_2[i] == current->num)
		   return (1);
	   i++;
   }
   return (0);
}
