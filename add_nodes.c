/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:59 by merdal            #+#    #+#             */
/*   Updated: 2024/02/27 16:47:13 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->num = content;
	new->next = NULL;
	return (new);
}

void	ft_add_to_stack(t_stack **a, t_stack *new_node)
{
	if (!a)
		return ;
	if (!*a)
		*a = new_node;
	else
		(ft_lstlast(*a))->next = new_node;
}

void	ft_add_nodes(t_stack **a, int content)
{
	t_stack	*new_node;

	new_node = ft_new_node(content);
	if (!new_node)
	{
		ft_error();
		return ;
	}
	ft_add_to_stack(a, new_node);
}
