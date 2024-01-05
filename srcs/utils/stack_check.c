/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:37:52 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/05 21:56:19 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_isdup(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->num == stack->num)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_stack_issorted(t_stack *stack)
{
	int	largest;

	largest = stack->num;
	while (stack)
	{
		if (largest > stack->num)
			return (0);
		else
			largest = stack->num;
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
