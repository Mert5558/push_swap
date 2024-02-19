/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:05 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:41:14 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_node;
	t_list	*node;

	if (!lst || !*lst || !del)
		return ;
	temp_node = *lst;
	while (temp_node)
	{
		node = temp_node;
		del(node->content);
		temp_node = temp_node->next;
		free(node);
	}
	*lst = NULL;
}
