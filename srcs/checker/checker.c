/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:37:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/13 22:07:04 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	exec_ops(char *ops, t_stack **stack_pair)
{
	if (!ft_strcmp(ops, "pa\n"))
		op_pa(stack_pair);
	else if (!ft_strcmp(ops, "pb\n"))
		op_pb(stack_pair);
	else if (!ft_strcmp(ops, "sa\n"))
		op_sa(stack_pair);
	else if (!ft_strcmp(ops, "sb\n"))
		op_sb(stack_pair);
	else if (!ft_strcmp(ops, "ss\n"))
		op_ss(stack_pair);
	else if (!ft_strcmp(ops, "ra\n"))
		op_ra(stack_pair);
	else if (!ft_strcmp(ops, "rb\n"))
		op_rb(stack_pair);
	else if (!ft_strcmp(ops, "rr\n"))
		op_rr(stack_pair);
	else if (!ft_strcmp(ops, "rra\n"))
		op_rra(stack_pair);
	else if (!ft_strcmp(ops, "rrb\n"))
		op_rrb(stack_pair);
	else if (!ft_strcmp(ops, "rrr\n"))
		op_rrr(stack_pair);
	else
		ft_error();
}

void	check_ops(char *ops, t_stack **stack_a)
{
	t_stack	*stack_pair[2];

	stack_pair[0] = *stack_a;
	stack_pair[1] = NULL;
	while (ops != NULL)
	{
		exec_ops(ops, stack_pair);
		ops = get_next_line(0);
	}
	if (ft_stack_issorted(stack_pair[0]))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*ops;

	stack_a = init_stack(argc, argv);
	if (!stack_a || ft_stack_isdup(stack_a))
	{
		ft_stackclear(&stack_a);
		ft_error();
	}
	ops = get_next_line(0);
	if (ft_stack_issorted(stack_a) && ops != NULL)
		ft_printf("KO\n");
	else
		check_ops(ops, &stack_a);
	free(stack_a);
	return (0);
}
