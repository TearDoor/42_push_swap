/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:37:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/06/19 14:34:10 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ops(char *ops, t_stack **stack_pair)
{
	const t_operations	operations[] = {
	{"pa\n", op_pa}, {"pb\n", op_pb},
	{"sa\n", op_sa}, {"sb\n", op_sb}, {"ss\n", op_ss},
	{"ra\n", op_ra}, {"rb\n", op_rb}, {"rr\n", op_rr},
	{"rra\n", op_rra}, {"rrb\n", op_rrb}, {"rrr\n", op_rrr},
	{NULL, NULL}
	};
	const t_operations	*ptr;

	ptr = operations;
	while (ptr->name != NULL)
	{
		if (ft_strcmp(ptr->name, ops) == 0)
		{
			ptr->func(stack_pair, 0);
			return ;
		}
		ptr++;
	}
	ft_error();
}

void	check_ops(char *ops, t_stack **stack_a)
{
	t_stack	*stack_pair[2];

	stack_pair[0] = *stack_a;
	stack_pair[1] = NULL;
	while (ops != NULL && *ops != '\0')
	{
		exec_ops(ops, stack_pair);
		free(ops);
		ops = get_next_line(0);
	}
	if (ft_stack_issorted(stack_pair[0]) && !stack_pair[1])
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(&stack_pair[0]);
	ft_stackclear(&stack_pair[1]);
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
	check_ops(ops, &stack_a);
	return (0);
}
