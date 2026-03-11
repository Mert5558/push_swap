/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:26:03 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 16:10:53 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = temp;
	(*a)->next = temp;
	temp->prev = *a;
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
	if (*b)
		(*b)->prev = NULL;
	(*a)->next = temp;
	if (temp)
		temp->prev = *a;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a, int i)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	temp = last;
	last->prev->next = NULL;
	temp->next = *a;
	(*a)->prev = temp;
	*a = temp;
	temp->prev = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}
