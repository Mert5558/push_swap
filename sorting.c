/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:27:59 by merdal            #+#    #+#             */
/*   Updated: 2024/02/28 14:22:56 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_stack **a)
{
    if (!a || !*a)
    {
        return (1);
    }
    int min_index = 0;
    long smallest_value = (*a)->num;
    int index = 0;
    t_stack *current = *a;

    while (current != NULL)
    {
        if (current->num < smallest_value)
        {
            smallest_value = current->num;
            min_index = index;
        }
        current = current->next;
        index++;
    }
	return (min_index);
}


void	ft_to_top(t_stack **a, t_stack **b)
{	
	int	smallest_index;

	smallest_index = ft_find_smallest(a);
	if (smallest_index < ft_lstsize(*a) / 2)
	{
		while (ft_find_smallest(a) != 0)
		{
			ft_ra(a, 0);
			smallest_index--;
		}
	}
	else
	{
		while (smallest_index < ft_lstsize(*a))
		{
			ft_rra(a, 0);
			smallest_index++;
		}
	}
	ft_pb(b, a, 0);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int	i;
	int	size_a;

	b = NULL;
	i = 0;
	size_a = ft_lstsize(*a);
	while (ft_lstsize(*a) != 0)
	{
		ft_to_top(a, &b);
	}
	while (ft_lstsize(b) != 0)
	{
		ft_pa(a, &b, 0);
	}
}
