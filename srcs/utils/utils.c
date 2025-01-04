/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:58:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/03/24 15:11:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	ft_compare(int a, int b, char mode)
{
	if (a > b)
	{
		if (mode == 'l')
			return (1);
		else
			return (0);
	}
	else if (a < b)
	{
		if (mode == 's')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	ft_arr_binary_search(int *arr, int size, int num)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + (high - low) / 2);
		if (arr[mid] == num)
			return (1);
		if (arr[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}
