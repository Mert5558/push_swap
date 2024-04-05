/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:27:17 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 16:09:59 by merdal           ###   ########.fr       */
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
	if ((*b)->next)
		(*b)->next->prev = temp;
	(*b)->next = temp;
	temp->prev = *b;
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
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (i == 0)
		write(1, "pb\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	temp = last;
	last->prev->next = NULL;
	temp->next = *b;
	(*b)->prev = temp;
	*b = temp;
	temp->prev = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}
