/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:58:42 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 15:30:27 by tkok-kea         ###   ########.fr       */
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
