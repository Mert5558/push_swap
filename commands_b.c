/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:27:17 by merdal            #+#    #+#             */
/*   Updated: 2024/03/12 10:55:31 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **b, int i)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next =temp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ft_pb(t_stack **b, t_stack **a, int i)
{
	t_stack	*temp;

	if ((*a) == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (i == 0)
		write(1, "pb\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*temp;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*temp;
	int		x;
	
	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	x = 0;
	temp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		x++;
	}
	(*b)->next = temp;
	while (x > 1)
	{
		temp = temp->next;
		x--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}