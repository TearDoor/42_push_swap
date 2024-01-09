/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 17:18:03 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort(t_stack *stack)
{
	t_stack	*stack_pair[2];
	int		stk_size;

	stack_pair[0] = stack;
	stack_pair[1] = NULL;
	stk_size = ft_stack_size(stack);
	if (stk_size == 2)
		op_sa(&stack_pair[0]);
	else if (stk_size == 3)
		sort_three(stack_pair);
	else
		sort_big(stack_pair, stk_size);
	ft_stackclear(&stack_pair[0]);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a || ft_stack_isdup(stack_a))
	{
		ft_stackclear(&stack_a);
		ft_error();
	}
	if (ft_stack_issorted(stack_a))
	{
		ft_stackclear(&stack_a);
		return (0);
	}
	sort(stack_a);
	return (0);
}
