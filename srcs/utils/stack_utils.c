/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:05 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/11/15 00:59:24 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_stacknew(int n)
{
	t_stack	*new;

	new = (t_stack *)malloc((sizeof(*new)));
	if (!new)
		ft_error();
	new->num = n;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackaddback(t_stack **stack, t_stack *new)
{
	t_stack	*curr;

	if (!stack)
		return ;
	if (*stack)
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	else
		*stack = new;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	if (!stack)
		return ;
	else
	{
		curr = *stack;
		while (curr)
		{
			temp = curr->next;
			curr->num = 0;
			free(curr);
			curr = temp;
		}
		*stack = NULL;
	}
}

/* void	ft_printstack(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return ;
	curr = stack;
	while (curr)
	{
		ft_putnbr_fd(curr->num, 1);
		ft_putchar_fd('\n', 1);
		curr = curr->next;
	}
} */
