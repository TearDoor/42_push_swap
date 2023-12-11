/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:53:51 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/11 21:48:38 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
int	rotate(t_stack **stack)
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

void	op_ra(t_stack **a)
{
	if (rotate(a) == -1)
		return ;
	ft_printf("ra\n");
}

void	op_rb(t_stack **b)
{
	if (rotate(b) == -1)
		return ;
	ft_printf("rb\n");
}

void	op_rr(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
