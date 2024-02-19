/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:06 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:38:12 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long	num;
	long	index;
	struct s_stack *next;
	struct s_stack *prev;
}t_stack;

char	**ft_split(char const *s, char c);
void	ft_error(void);
int		ft_atoi(const char *str);
t_stack	*ft_process_normal(int argc, char **argv);
t_stack	*ft_process_quotation(char **argv);
void	ft_add_nodes(t_stack **stack, int content);

#endif