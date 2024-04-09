/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:06 by merdal            #+#    #+#             */
/*   Updated: 2024/04/09 13:11:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
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
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a);
void	ft_add_to_stack(t_stack **a, t_stack *new_node);
void	ft_check_push(t_stack **a, t_stack **b);
t_stack	*ft_new_node(int content);
int		ft_find_smallest(t_stack **a);
int		ft_find_biggest(t_stack **stack);
int		ft_find_mid(t_stack **a, t_stack **b);
int		ft_calc_moves(t_stack **a, int index);
int		*ft_fake_chunks(int chunk_size);
int		ft_scan_top(t_stack **a, int *chunk, int chunk_size);
int		ft_scan_bottom(t_stack **a, int *chunk, int chunk_size);
void	ft_scan_move(t_stack **a, int *chunk, int chunk_size);
int		ft_calc_moves(t_stack **a, int index);
void	ft_calc_which_command(t_stack **a, int	index, int moves);
void	ft_calc_which_command_b(t_stack **b, int	index, int moves);
void	ft_sort_b(t_stack **a, t_stack **b);
void	ft_biggest_to_top(t_stack **b);
void	print_array(int *arr, int size);
void	ft_sort_a(t_stack **a, t_stack **b);
int		*ft_create_chunk(t_stack **b, int chunk_size);
int		ft_check_if_smallest(t_stack **b, t_stack **a);
int		ft_check_if_biggest(t_stack **b, t_stack **a);
void	ft_smallest_to_top(t_stack **b);
void	ft_mid_to_top(t_stack **a, t_stack **b);
void	ft_biggest_to_top(t_stack **b);
void	ft_index_to_top(t_stack **a, int index);
int		*ft_make_chunk_2(t_stack **b, int chunk_size);
int		ft_choose(t_stack **a, t_stack **b, int *chunk_2, int chunk_size);
int		ft_choose_bottom(t_stack **a, t_stack **b, int *chunk_2, int chunk_size);
int		ft_find_less_moves(int *options, int size_options);
int		*ft_get_options(t_stack **a, t_stack **b, int size_options);
int		*ft_get_options_bottom(t_stack **a, t_stack **b, int size_options);
int		ft_moves_options(t_stack **a, t_stack *value);
int 	ft_check_if_biggest2(t_stack **a, t_stack *value);
int		ft_check_if_smallest2(t_stack **a, t_stack *value);
int		ft_mid_to_top_moves(t_stack **a, t_stack *value);
int		ft_smallest_to_top_moves(t_stack **a);
int		ft_biggest_to_top_moves(t_stack **a);
int		ft_is_in_chunk(int *chunk_2, t_stack *current);
int		ft_is_chunk_finished(t_stack **b, int *chunk_2);
int		ft_finished_top(t_stack **b, int *chunk_2);
int		ft_finished_bottom(t_stack **b, int *chunk_2);
void	ft_sort_3(t_stack **a);
void	ft_rough_sort(t_stack **a, t_stack **b);
void	ft_last_sort(t_stack **a, t_stack **b);
void	ft_sort_5(t_stack **a, t_stack **b);
int		ft_smallest_value(t_stack **a);
int		ft_next_value(t_stack **a, int value);
int		*ft_make_chunk(t_stack **a, int chunk_size);
void	ft_sort_small(t_stack **a, t_stack **b);

#endif