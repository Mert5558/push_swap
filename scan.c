/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:10:36 by merdal            #+#    #+#             */
/*   Updated: 2024/03/08 16:38:19 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_last_stack(t_stack **a)
{
	t_stack	*current = *a;

	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	ft_scan_top(t_stack **a, int *chunk)
{
	int index_chunk = 0;
	int	index_stack = 0;
	t_stack *current = *a;

	while (current != NULL)
	{
		while (index_chunk <= 20)
		{
			if (current->num == chunk[index_chunk])
			{
				printf("%d\n", index_stack);
				return (index_stack);
			}
			index_chunk++;
		}
		index_chunk = 0;
		current = current->next;
		index_stack++;
	}
	return (0);
}

int	ft_scan_bottom(t_stack **a, int *chunk)
{
	int index_chunk = 0;
	int	index_stack = ft_lstsize(*a) - 1;
	t_stack *current = ft_get_last_stack(a);

	while (current != *a)
	{
		while (index_chunk <= 20)
		{
			if (current->num == chunk[index_chunk])
			{
				printf("%d\n", index_stack);
				return(index_stack);
			}
			index_chunk++;
		}
		index_chunk = 0;
		current = current->prev;
		index_stack--;
	}
	return (0);
}
