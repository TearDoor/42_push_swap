/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:09:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/13 16:49:18 by tkok-kea         ###   ########.fr       */
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

void	op_pa(t_stack *stacks[2])
{
	if (!stacks[1])
		return ;
	stack_push(&stacks[0], stack_pop(&stacks[1]));
	ft_putendl_fd("pa", 1);
}

void	op_pb(t_stack *stacks[2])
{
	if (!stacks[0])
		return ;
	stack_push(&stacks[1], stack_pop(&stacks[0]));
	ft_putendl_fd("pb", 1);
}
