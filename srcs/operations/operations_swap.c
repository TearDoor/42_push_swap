/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:12:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/03/24 15:10:44 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return (-1);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (0);
}

void	op_sa(t_stack **stacks, int print)
{
	if (swap(&stacks[0]) == -1)
		return ;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	op_sb(t_stack **stacks, int print)
{
	if (swap(&stacks[1]) == -1)
		return ;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	op_ss(t_stack **stacks, int print)
{
	if (!stacks[0] || !stacks[0]->next || !stacks[1] || !stacks[1]->next)
		return ;
	swap(&stacks[0]);
	swap(&stacks[1]);
	if (print)
		ft_putendl_fd("ss", 1);
}
