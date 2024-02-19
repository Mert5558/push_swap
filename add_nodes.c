/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:59 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:37:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->num = content;
	new->next = NULL;
	return (new);
}

void	ft_add_to_stack(t_stack **stack, t_stack *new_stack)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else
		(ft_lstlast(*stack))->next = new_stack;
}

void	ft_add_nodes(t_stack **stack, int content)
{
	t_stack *new_node;

	new_node = ft_new_stack(content);
	if (!new_node)
	{
		ft_error();
		return ;
	}
	ft_add_to_stack(stack, new_node);
}