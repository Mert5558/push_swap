/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:53:52 by merdal            #+#    #+#             */
/*   Updated: 2024/03/26 16:01:21 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

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

int	*ft_get_options(t_stack **a, t_stack **b, int size_options)
{
	t_stack	*current = *b;
	int	*options;
	int	i = 0;

	options = (int *)malloc(sizeof(int) * size_options);
	if (!options)
		return (NULL);

	while (i < size_options)
	{
		options[i] = ft_moves_options(a, current) + i;
		i++;
		current = current->next;
	}
	return (options);
}

int ft_is_in_chunk(t_stack **b, int *chunk_2, int size_options)
{
    int count = 0;
    t_stack *current = *b;

    while (current != NULL && count < size_options)
    {
        int i = 0;
        while (i < size_options)
        {
            if (current->num == chunk_2[i])
            {
                count++;
                break;                     // fehler hier
            }
            i++;
        }
        current = current->next;
    }
	printf("count: %d\n", count);
    return (count);
}

void	ft_choose(t_stack **a, t_stack **b, int *chunk_2)
{
	int	*options;
	int	less_moves;
	int	size_options = 15;

	if (ft_lstsize(*b) < size_options)
		size_options = ft_lstsize(*b);

	size_options = ft_is_in_chunk(b, chunk_2, size_options);

	options = ft_get_options(a, b, size_options);

	if (!options)
		ft_error();

	less_moves = ft_find_less_moves(options, size_options);

	ft_index_to_top(b, less_moves);

	free(options);
}
