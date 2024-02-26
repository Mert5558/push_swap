/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:50:52 by merdal            #+#    #+#             */
/*   Updated: 2024/02/26 12:41:47 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}
