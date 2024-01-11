/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:29:16 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/11 16:42:21 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* calculates the cost for all elements to rotate to the top
positive means rotations and negative means reverse rotations*/
void	ft_stack_rotate_cost(t_stack *stack)
{
	int	i;
	int	size;
	int	mid;

	i = 0;
	size = ft_stack_size(stack);
	mid = size / 2;
	while (stack)
	{
		if (i <= mid)
			stack->cost.own = i;
		else
			stack->cost.own = i - size;
		stack = stack->next;
		i++;
	}
	return ;
}

t_stack	*ft_stack_most(t_stack *stack, char mode, char item)
{
	t_stack	*most;

	most = stack;
	while (stack)
	{
		if (item == 'n')
		{
			if (ft_compare(stack->num, most->num, mode))
				most = stack;
		}
		else if (item == 'c')
		{
			if (ft_compare(stack->cost.total, most->cost.total, mode))
				most = stack;
		}
		stack = stack->next;
	}
	return (most);
}

int	ft_find_target_btoa(t_stack *stack_a, int nbr)
{
	t_stack	*target;
	t_stack	*curr;

	target = NULL;
	curr = stack_a;
	while (curr)
	{
		if (curr->num > nbr)
		{
			if (!target)
				target = curr;
			else if (curr->num < target->num)
				target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		target = ft_stack_most(stack_a, 's', 'n');
	return (target->cost.own);
}

int	ft_cost_total(int cost1, int cost2)
{
	if (cost1 > 0 && cost2 > 0)
	{
		if (cost1 > cost2)
			return (cost1);
		else
			return (cost2);
	}
	else if (cost1 < 0 && cost2 < 0)
	{
		if (cost1 < cost2)
			return (ft_abs(cost1));
		else
			return (ft_abs(cost2));
	}
	else
		return (ft_abs(cost1) + ft_abs(cost2));
}

void	ft_stack_total_cost(t_stack *src_stack, t_stack *dst_stack)
{
	int	dst_cost;

	ft_stack_rotate_cost(src_stack);
	ft_stack_rotate_cost(dst_stack);
	while (src_stack)
	{
		dst_cost = ft_find_target_btoa(dst_stack, src_stack->num);
		src_stack->cost.dst = dst_cost;
		src_stack->cost.total = ft_cost_total(src_stack->cost.own, dst_cost);
		src_stack = src_stack->next;
	}
	return ;
}
