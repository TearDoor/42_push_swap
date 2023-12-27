/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:35:52 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/27 18:57:50 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* find_lis: function to find LIS (Largest Increasing Subsequence)
in stack A so that we dont need to push those numbers to stack B */

/* receives a stack of numbers and it's size to return an allocated array */
int	*stack_to_array(t_stack *stack, int size)
{
	int	*num;
	int	i;

	num = (int *)malloc(sizeof(int) * size);
	if (!num)
		ft_error();
	i = 0;
	while (stack != NULL)
	{
		num[i++] = stack->num;
		stack = stack->next;
	}
	return (num);
}

/* finds numbers from stack A from the bottom to construct a LIS
because we start pushing to B from the top of A */
int	*create_lis(int *num, int num_size, int *lis_len, int lis_max)
{
	int	i;
	int	*lis;

	lis = (int *)malloc(sizeof(int) * lis_max);
	if (!lis)
		return (NULL);
	i = num_size;
	while (--i >= 0)
	{
		if (lis_len[i] == lis_max)
		{
			lis_max--;
			lis[lis_max] = num[i];
			if (lis_max == 0)
				break ;
		}
	}
	return (lis);
}

/* allocates an array same size as num and initialize it with integer 1 */
int	*lis_len_init(int size)
{
	int	i;
	int	*lis_len;

	lis_len = (int *)malloc(sizeof(int) * size);
	if (!lis_len)
		return (NULL);
	i = 0;
	while (i < size)
	{
		lis_len[i] = 1;
		i++;
	}
	return (lis_len);
}

/* finds the length of LIS and that is stored in lis_max 
returns an allocated array created with create_lis */
int	*find_lis(int *num, int num_size, int *lis_max)
{
	int	*lis_len;
	int	i;
	int	j;

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
	free(lis_len);
	return (create_lis(num, num_size, lis_len, *lis_max));
}
/*
int main(void)
{
	int num[] = {5, 4, 3, 2, 1};
	int num_size;
	int	*lis;
	int lis_size;
	int i;

	num_size = sizeof(num)/sizeof(int);
	lis_size = 0;
	lis = find_lis(num, num_size, &lis_size);

	printf("LIS length: %d\n", lis_size);
	i = 0;
	while (i < lis_size)
		printf("%d ", lis[i++]);

	free(lis);
	return (0);
}
*/
