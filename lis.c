/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:35:52 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/21 15:08:20 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/* function to find LIS (Largest Increasing Subsequence)
in stack A so that we dont need to push those numbers to stack B */


/* allocates an array same size as num and initialize it with 1s */
int	*lis_len_init(int size)
{
	int *lis_len;
	int i;

	lis_len = (int *)malloc(sizeof(int) * size);
	if (!lis_len)
		return NULL;
	i = 0;
	while (i < size)
	{
		lis_len[i] = 1;
		i++;
	}
	return (lis_len);
}

int	*find_lis(int *num, int num_size, int *lis_max)
{
	int	*lis_len;
	int i;
	int j;

	lis_len = lis_len_init(num_size);
	i = 0;
	while (i < num_size)
	{
		j = i;
		while (j < num_size)
		{
			if (num[j] > num[i] && lis_len[i] == lis_len[j])
			{
				lis_len[j] += 1;
				if (lis_len[j] > *lis_max)
					*lis_max = lis_len[j];
			}
			j++;
		}
		i++;
	}
	return (lis_len);
}

int main(void)
{
	int num[10] = {10, 72, 9, 33, 21, 50, 41, 60, 55, 70};
	int	*lis;
	int lis_size;
	int i;

	lis_size = 0;
	lis = find_lis(num, 10, &lis_size);

	printf("LIS length: %d\n", lis_size);
	i = 0;
	while (i < 10)
		printf("%d ", lis[i++]);

	return (0);
}