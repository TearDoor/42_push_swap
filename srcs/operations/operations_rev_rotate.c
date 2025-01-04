/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:55:36 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/03/24 15:10:36 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (temp->next->next)
		temp = temp->next;
	tail->next = *stack;
	*stack = tail;
	temp->next = NULL;
	return (0);
}

void	op_rra(t_stack **stacks, int print)
{
	if (rev_rotate(&stacks[0]) == -1)
		return ;
	if (print)
		ft_printf("rra\n");
}

void	op_rrb(t_stack **stacks, int print)
{
	if (rev_rotate(&stacks[1]) == -1)
		return ;
	if (print)
		ft_printf("rrb\n");
}

void	op_rrr(t_stack **stacks, int print)
{
	if (!stacks[0] || !stacks[0]->next || !stacks[1] || !stacks[1]->next)
		return ;
	rev_rotate(&stacks[0]);
	rev_rotate(&stacks[1]);
	if (print)
		ft_putendl_fd("rrr", 1);
}
