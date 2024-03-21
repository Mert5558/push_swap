/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:53:52 by merdal            #+#    #+#             */
/*   Updated: 2024/03/21 12:54:34 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest_to_top_moves(t_stack **a)
{
	int	index_biggest;
	int	moves;
	
	index_biggest = ft_find_biggest(a);
	moves = ft_calc_moves(a, index_biggest);

	return (moves);
}

int	ft_smallest_to_top_moves(t_stack **a)
{
	int	index_smallest;
	int	moves;
	
	index_smallest = ft_find_smallest(a);
	moves = ft_calc_moves(a, index_smallest);

	return (moves);
}

int	ft_mid_to_top_moves(t_stack **a, t_stack *value)
{
	int	index_mid;
	int	moves;

	index_mid = ft_find_mid(a, &value);
	moves = ft_calc_moves(a, index_mid);

	return (moves);
}

int	ft_check_if_smallest2(t_stack **a, t_stack *value)
{
	t_stack	*current = *a;

	while (current != NULL)
	{
		if (value->num >= current->num)
			return (1);
		current = current->next;
	}
	return (0);
}

int ft_check_if_biggest2(t_stack **a, t_stack *value)
{
    t_stack *current = *a;

    while (current != NULL)
    {
        if (value->num <= current->num)
            return (1);
        current = current->next;
    }
    return (0);
}


int	ft_moves_options(t_stack **a, t_stack *value)
{
	int	moves  = 0;
	
	if (ft_check_if_smallest2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_biggest2(a, value) == 0)
	{
		moves = ft_smallest_to_top_moves(a);
		return (moves);
	}
	else if (ft_check_if_smallest2(a, value) == 1 && ft_check_if_biggest2(a, value) == 1)
	{
		moves = ft_mid_to_top_moves(a, value);
		return (moves);
	}
	return (moves);
}


int	*ft_get_options(t_stack **a, t_stack **b)
{
	t_stack	*current = *b;
	int	*options;
	int	i = 0;

	options = (int *)malloc(sizeof(int) * 4);
	if (!options)
		return (NULL);

	while (i < 4)
	{
		options[i] = ft_moves_options(a, current) + i;
		i++;
		current = current->next;
	}
	return (options);
}

int	ft_find_less_moves(int *options)
{
	int	i = 0;
	int	less_moves = options[0];

	while (i < 4)
	{
		if (options[i] < less_moves)
			less_moves = options[i];
		i++;
	}
	return (less_moves);
}

void	ft_choose(t_stack **a, t_stack **b)
{
	int	*options;
	int	less_moves;

	options = ft_get_options(a, b);
	if (!options)
		ft_error();
	less_moves = ft_find_less_moves(options);
	ft_index_to_top(b, less_moves);
	free(options);
}
