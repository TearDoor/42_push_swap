/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/28 16:45:43 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(t_stack *stack)
{
	t_stack *stack_pair[2];
	int		stk_size;

	stack_pair[0] = stack;
	stack_pair[1] = NULL;
	stk_size = ft_stack_size(stack_pair[0]);
	if (stk_size == 2)
		op_sa(&stack_pair[0]);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a || stack_isdup(stack_a))
		ft_error();
	if (stack_issorted(stack_a))
		return (0);
	sort(stack_a);
	ft_stackclear(&stack_a);
	return (0);
}
