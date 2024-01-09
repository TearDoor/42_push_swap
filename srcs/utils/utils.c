/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:58:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 17:45:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	else
	{
		if (mode == 's')
			return (1);
		else
			return (0);
	}
}

int	ft_array_search(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i++] == num)
			return (1);
	}
	return (0);
}
