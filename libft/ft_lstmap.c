/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:57 by merdal            #+#    #+#             */
/*   Updated: 2024/02/19 14:41:59 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*temp_lst;
	void	*new_content;

	new_lst = NULL;
	temp_lst = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (temp_lst)
	{
		new_content = f(temp_lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp_lst = temp_lst->next;
	}
	return (new_lst);
}
