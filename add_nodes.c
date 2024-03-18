/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:59 by merdal            #+#    #+#             */
/*   Updated: 2024/03/18 11:04:33 by merdal           ###   ########.fr       */
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
        *a = new_node;
        new_node->prev = NULL;
    } else {
        t_stack *last_node = ft_lstlast(*a);
        last_node->next = new_node;
        new_node->prev = last_node;
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
