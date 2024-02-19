/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:35 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:41:43 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*temp_lst;

	temp_lst = lst;
	if (!lst || !f)
		return ;
	while (temp_lst)
	{
		f(temp_lst->content);
		temp_lst = temp_lst->next;
	}
}
