/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/21 16:25:11 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_pair[2];

	stack_pair[0] = init_stack(argc, argv);
	stack_pair[1] = NULL;
	if (!stack_pair[0] || stack_isdup(stack_pair[0]))
		ft_error();
	if (stack_issorted(stack_pair[0]))
		ft_putendl_fd("Is sorted", 1);
	ft_print_both_stacks(stack_pair);
	op_pb(stack_pair);
	op_pb(stack_pair);
	op_pb(stack_pair);
	ft_print_both_stacks(stack_pair);
	op_ss(stack_pair);
	ft_print_both_stacks(stack_pair);
	ft_stackclear(&stack_pair[0]);
	return (0);
}
