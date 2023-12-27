/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:37:52 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/27 19:03:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_isdup(t_stack *stack)
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

int	stack_issorted(t_stack *stack)
{
	int	largest;

	largest = stack->num;
	while (stack)
	{
		if (largest > stack->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while(stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
