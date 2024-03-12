/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/08 18:37:19 by merdal           ###   ########.fr       */
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

void ft_add_to_stack(t_stack **a, t_stack *new_node)
{
    if (!a)
        return;
    
    if (!*a) {
        // If the stack is empty, set the new node as both the first and last node
        *a = new_node;
        new_node->prev = NULL; // Ensure that the prev pointer of the first node is NULL
    } else {
        t_stack *last_node = ft_lstlast(*a);
        last_node->next = new_node; // Update the next pointer of the last node
        new_node->prev = last_node; // Set the prev pointer of the new node
    }
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
