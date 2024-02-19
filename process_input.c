/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:12:12 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:30:45 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_process_quotation(char **argv)
{
	t_stack	*a;
	int		i;
	int		j;
	char	**temp;

	a = NULL;
	i = 0;
	temp = ft_split(argv[1], 32);
	while (temp[i])
	{
		j = ft_atoi(temp[i]);
		ft_add_nodes(&a, j);
		i++;
	}
	return (a);
}

t_stack	*ft_process_normal(int argc, char **argv)
{
	t_stack *a;
	int		i;
	int		j;
	
	i = 1;
	a = NULL;
	while (i < argc)
	{
		j = ft_atoi(argv[i]);
		ft_add_nodes(&a, j);
		i++;
	}
	return (a);
}