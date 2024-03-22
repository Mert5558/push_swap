/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:26:03 by merdal            #+#    #+#             */
/*   Updated: 2024/03/22 14:52:13 by merdal           ###   ########.fr       */
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
    if ((*a)->next)  // Check if there's a third node
        (*a)->next->prev = temp;  // Update the prev pointer of the third node
    (*a)->next = temp;
    temp->prev = *a;  // Update the prev pointer of the second node
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
    if (*b) // Check if b is not empty after the pop
        (*b)->prev = NULL; // Update the prev pointer of the new first node of b
    (*a)->next = temp;
    if (temp) // Check if a was not empty before the push
        temp->prev = *a; // Update the prev pointer of the second node of a
    if (i == 0)
        write(1, "pa\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
    t_stack *temp;
    t_stack *last;

    if ((*a) == NULL || (*a)->next == NULL)
        return;
    
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
    while (last->next) // Find the last node
        last = last->next;

    temp = last; // Save the last node
    last->prev->next = NULL; // Disconnect the last node from the second last node
    temp->next = *a; // Connect the new first node to the old first node
    (*a)->prev = temp; // Update the prev pointer of the old first node
    *a = temp; // Move the head pointer to the last node
    temp->prev = NULL; // Update the prev pointer of the new first node

    if (i == 0)
        write(1, "rra\n", 4);
}
