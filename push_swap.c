/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:28 by merdal            #+#    #+#             */
/*   Updated: 2024/04/05 14:23:08 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_process_quotation(argv);
	else
		a = ft_process_normal(argc, argv);
	if (ft_checkfordup(a) || a == NULL)
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checkifsorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
