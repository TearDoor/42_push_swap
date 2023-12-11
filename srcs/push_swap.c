/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/11 21:47:30 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	if (!stack_a || stack_isdup(stack_a))
		ft_error();
	if (stack_issorted(stack_a))
		ft_putendl_fd("Is sorted", 1);
	op_pa(&stack_a, &stack_b);
	op_pa(&stack_a, &stack_b);
	op_pa(&stack_a, &stack_b);
	ft_print_both_stacks(stack_a, stack_b);
	op_rrr(&stack_a, &stack_b);
	ft_print_both_stacks(stack_a, stack_b);
	op_rrb(&stack_b);
	ft_print_both_stacks(stack_a, stack_b);
	ft_stackclear(&stack_a);
	stack_a = NULL;
	return (0);
}
