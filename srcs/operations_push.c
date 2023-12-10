/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:09:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/10 18:57:55 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*adds a new node to top of stack*/
void	stack_push(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	new->next = *stack;
	*stack = new;
}

/*removes and returns the top node of a stack*/
t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*top;

	if (!*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	return (top);
}

void	op_pa(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	stack_push(b, stack_pop(a));
	ft_putendl_fd("pa", 1);
}

void	op_pb(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	stack_push(a, stack_pop(b));
	ft_putendl_fd("pb", 1);
}
