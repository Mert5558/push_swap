/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:27:17 by merdal            #+#    #+#             */
/*   Updated: 2024/03/22 14:51:12 by merdal           ###   ########.fr       */
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
    if ((*b)->next)  // Check if there's a third node
        (*b)->next->prev = temp;  // Update the prev pointer of the third node
    (*b)->next = temp;
    temp->prev = *b;  // Update the prev pointer of the second node
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
    if (*a) // Check if a is not empty after the pop
        (*a)->prev = NULL; // Update the prev pointer of the new first node of a
    temp->next = *b;
    if (*b) // Check if b was not empty before the push
        (*b)->prev = temp; // Update the prev pointer of the second node of b
    *b = temp;
    if (i == 0)
        write(1, "pb\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
    t_stack *temp;
    t_stack *last;

    if ((*b) == NULL || (*b)->next == NULL)
        return;
    
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
    while (last->next) // Find the last node
        last = last->next;

    temp = last; // Save the last node
    last->prev->next = NULL; // Disconnect the last node from the second last node
    temp->next = *b; // Connect the new first node to the old first node
    (*b)->prev = temp; // Update the prev pointer of the old first node
    *b = temp; // Move the head pointer to the last node
    temp->prev = NULL; // Update the prev pointer of the new first node

    if (i == 0)
        write(1, "rrb\n", 4);
}
