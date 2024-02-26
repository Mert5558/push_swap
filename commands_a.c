/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:26:03 by merdal            #+#    #+#             */
/*   Updated: 2024/02/26 12:40:36 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*temp;

	if (a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if ((*b) == NULL)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*temp;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a, int i)
{
	t_stack	*temp;
	int		x;
	
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	x = 0;
	temp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		x++;
	}
	(*a)->next = temp;
	while (x > 1)
	{
		temp = temp->next;
		x--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}
