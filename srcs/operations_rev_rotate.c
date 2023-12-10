/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:55:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/10 18:58:32 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
int	rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return (-1);
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	temp = *stack;
	*stack = (*stack)->next;
	tail->next = temp;
	temp->next = NULL;
	return (0);
}

void op_rra(t_stack **a)
{
	if (rev_rotate(a) == -1)
		return ;
	ft_printf("ra\n");
}

void op_rrb(t_stack **b)
{
	if (rev_rotate(b) == -1)
		return ;
	ft_printf("rb\n");
}

void	op_rrr(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("ss", 1);
}