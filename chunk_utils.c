/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/03/11 15:10:09 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_update_chunk(int *chunk)
{
	int	i = 0;
	while (i < 20)
	{
		chunk[i] = chunk[i] + 20;
		i++;
	}
	return (chunk);
}