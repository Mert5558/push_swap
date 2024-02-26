/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:06 by merdal            #+#    #+#             */
/*   Updated: 2024/02/26 12:44:49 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

void	ft_error(void);
void	ft_add_nodes(t_stack **stack, int content);
t_stack	*ft_process_normal(int argc, char **argv);
t_stack	*ft_process_quotation(char **argv);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		ft_checkfordup(t_stack *a);
void	ft_free(t_stack **lst);
int		ft_checkifsorted(t_stack *stack_a);
void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void 	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_pb(t_stack **b, t_stack **a, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_sort(t_stack **a);

#endif