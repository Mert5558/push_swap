/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:10:36 by merdal            #+#    #+#             */
/*   Updated: 2024/03/08 15:43:22 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_scan_top(t_stack **a, int *chunk)
{
	int index_chunk = 0;
	int	index_stack = 0;
	t_stack *current = *a;

	while (current != NULL)
	{
		if (current->num == chunk[index_chunk])
		{
			printf("%d\n", index_stack);
			return (index_stack);
		}
		current = current->next;
		index_stack++;
	}
	return (0);
}

void	ft_scan_bottom(t_stack **a, int *chunk)
{
	
}