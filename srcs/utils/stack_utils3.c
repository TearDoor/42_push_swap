/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:42:37 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 18:05:26 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_stack_a_cheapest(t_stack *stack, int *lis, int lis_size)
{
	t_stack	*cheapest;

	while (stack && ft_array_search(lis, lis_size, stack->num))
		stack = stack->next;
	cheapest = stack;
	while (stack)
	{
		if (stack->cost.total < cheapest->cost.total && !ft_array_search(lis, lis_size, stack->num))
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}