/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:12:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/11/18 18:08:32 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	op_sa(t_stack **a)
{
	if (swap(a) == -1)
		return ;
	ft_putendl_fd("sa", 1);
}

void	op_sb(t_stack **b)
{
	if(swap(b) == -1)
		return ;
	ft_putendl_fd("sb", 1);
}

