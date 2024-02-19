/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:28 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 12:51:26 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;

	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_process_quotation(**argv);
	else
		a = ft_process_normal(argc, **argv);
}
