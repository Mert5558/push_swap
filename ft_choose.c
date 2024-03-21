/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:53:52 by merdal            #+#    #+#             */
/*   Updated: 2024/03/21 16:58:15 by merdal           ###   ########.fr       */
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

void	ft_choose(t_stack **a, t_stack **b)
{
	int	*options;
	int	*options_2;
	int	less_moves;
	int	less_moves_2;
	int	temp;
	int	size_options = 3;

	options = ft_get_options(a, b, size_options);
	options_2 = ft_get_options_bottom(a, b, size_options);
	print_array(options, size_options);
	print_array(options_2, size_options);
	if (!options || !options_2)
		ft_error();

	less_moves = ft_find_less_moves(options, size_options);
	temp = ft_find_less_moves(options_2, size_options);
	less_moves_2 = ft_lstsize(*b) + temp;
	printf("less_moves: %d\n", less_moves);
	printf("less_moves_2: %d\n", less_moves_2);
	printf("temp: %d\n", temp);

	if (options[less_moves] <= options_2[temp])
		ft_index_to_top(b, less_moves);
	else
		ft_index_to_top(b, less_moves_2);

	free(options);

	// 36 2 29 32 3 31 42 4 10 45 24 18 20 25 28 21 19 16 12 49 27 50 23 13 41 6 47 39 26 9 48 37 14 7 35 5 11 40 43 34 8 22 30 46 33 15 1 38 17 44 
}
