/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:40:18 by merdal            #+#    #+#             */
/*   Updated: 2024/03/07 12:28:48 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_chunks(int **chunks, int chunks_amount) {
    for (int i = 0; i < chunks_amount; i++) {
        printf("Chunk %d: ", i + 1);
        for (int j = 0; chunks[i][j] != -1; j++) {
            printf("%d ", chunks[i][j]);
        }
        printf("\n");
    }
}

void	ft_free_chuks(int chunks_amout, int **chunks)
{
	int i;

	i = 0;
	while (i < chunks_amout)
	{
		free(chunks[i]);
		i++;
	}
	free(chunks);
}

int	ft_calculate_chunk_size(int stack_len, int chunk_size)
{
	int chunks_amount;

	chunks_amount = stack_len / chunk_size;
	if (stack_len % chunk_size != 0)
		chunks_amount++;
	return (chunks_amount);
}

int **ft_allocate_chunks(int chunks_amount, int chunk_size)
{
	int	**chunks;
	int i;

	i = 0;
	chunks = malloc(chunks_amount * sizeof(int *));
	if (!chunks)
		ft_error();
	while (i < chunks_amount)
	{
		chunks[i] = malloc(chunk_size * sizeof(int));
		i++;
	}
	return (chunks);
}

void	ft_init_chunk_values(int **chunks, int chunks_amount, int last_chunk_size, int chunk_size)
{
    int i;
    int j;
    int size;

    i = 0;
    while (i < chunks_amount)
    {
        size = (i == chunks_amount - 1) * last_chunk_size + (i != chunks_amount - 1) * chunk_size;
        j = 0;
        while (j < size)
        {
            chunks[i][j] = i * chunk_size + j;
            j++;
        }
        i++;
    }
}


int	**ft_make_chunks(t_stack **a)
{
	int stack_len;
    int chunk_size;
    int last_chunk_size;
    int chunks_amount;
    int** chunks;

	stack_len = ft_lstsize(*a);
	chunk_size = 20;
	last_chunk_size = stack_len % chunk_size;
	chunks_amount = ft_calculate_chunk_size(stack_len, chunk_size);
	chunks = ft_allocate_chunks(chunks_amount, chunk_size);
    ft_init_chunk_values(chunks, chunks_amount, last_chunk_size, chunk_size);
	print_chunks(chunks, chunks_amount);
	ft_free_chuks(chunks_amount, chunks);
	return (chunks);
}
