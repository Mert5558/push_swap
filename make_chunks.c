/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:18 by merdal            #+#    #+#             */
/*   Updated: 2024/03/06 14:46:55 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_chunks(int **chunks, int chunks_amount, int chunk_size) {
//     for (int i = 0; i < chunks_amount; i++) {
//         printf("Chunk %d:", i + 1);
//         for (int j = 0; j < chunk_size; j++) {
//             printf(" %d", chunks[i][j]);
//         }
//         printf("\n");
//     }
// }

void	ft_free_chuks(int i, int chunks_amout, int **chunks)
{
	i = 0;
	while (i < chunks_amout)
	{
		free(chunks[i]);
		i++;
	}
	free(chunks);
}

void	ft_make_chunks(t_stack **a)
{
	int	stack_len;
	int	chunks_amout;
	int	**chunks = NULL;
	int	size;
	int	chunk_size = 20;
	int	last_chunk_size;
	int	i = 0;
	int	j = 0;

	stack_len = ft_lstsize(*a);
	chunks_amout = stack_len / chunk_size;
	if (stack_len % chunk_size != 0)
		chunks_amout++;
	
	chunks = malloc(chunks_amout * sizeof(int *));
	if (!chunks)
		ft_error();

	if (stack_len % chunk_size != 0)
		last_chunk_size = stack_len % chunk_size;
	else
		last_chunk_size = chunk_size;
	
	while (i < chunks_amout)
	{
		if (i == chunks_amout - 1)
			size = last_chunk_size;
		else
			size = chunk_size;
		
		chunks[i] = malloc(size * sizeof(int));
		if (!chunks[i])
			ft_error();
		
		j = 0;
		while (j < size)
		{
			chunks[i][j] = i * 20 + j;
			j++;
		}
		i++;
	}
	ft_free_chuks(i, chunks_amout, chunks);
}

