/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:47:30 by merdal            #+#    #+#             */
/*   Updated: 2024/03/14 13:17:18 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int	*ft_update_chunk(int *chunk)
{
	int	i = 0;
	while (i < 20)
	{
		chunk[i] += 20;
		i++;
	}
	return (chunk);
}

int *ft_fake_chunks(void)
{
	int	*chunk;
	int	i = 0;
	int	value = 0;
	
	chunk = malloc(20 * sizeof(int));
	if (chunk == NULL)
		return (NULL);
	
	while (i < 20)
	{
		chunk[i] = value;
		i++;
		value++;
	}
	return (chunk);
}

// int main(void) {
//     int *chunk = ft_fake_chunks();

//     printf("Chunk before update:\n");
//     print_array(chunk, 20); // Pass the size of the array

//     chunk = ft_update_chunk(chunk);

//     printf("Chunk after update:\n");
//     print_array(chunk, 20); // Pass the size of the array

//     free(chunk); // Don't forget to free the allocated memory
//     return 0;
// }
