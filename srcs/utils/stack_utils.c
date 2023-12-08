/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:05 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/08 19:08:41 by tkok-kea         ###   ########.fr       */
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

void	ft_printstack(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return ;
	curr = stack;
	while (curr)
	{
		ft_putnbr_fd(curr->num, 1);
		ft_putchar_fd(' ', 1);
		curr = curr->next;
	}
}

void	ft_print_both_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stack A: top -> bottom\n");
	ft_printstack(a);
	ft_printf("\n");
	ft_printf("Stack B: top -> bottom\n");
	ft_printstack(b);
	ft_printf("\n");
}
