/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/30 21:22:53 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* returns the index of the biggest number in a stack */
int	max_num_index(t_stack *stack)
{
	int	max;
	int i;
	int	max_i;

	max = stack->num;
	i = 0;
	max_i = i;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_i = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_i);
}

/* makes sure largest num at bottom then swaps top 2 if necessary */
void	sort_three(t_stack **stack)
{
	int max_i;
	
	max_i = max_num_index(*stack);
	if (max_i == 0)
		op_ra(stack);
	else if (max_i == 1)
		op_rra(stack);
	if (!stack_issorted(*stack))
		op_sa(stack);
}

static void	sort(t_stack *stack)
{
	t_stack *stack_pair[2];
	int		stk_size;

	stack_pair[0] = stack;
	stack_pair[1] = NULL;
	stk_size = ft_stack_size(stack_pair[0]);
	if (stk_size == 2)
		op_sa(&stack_pair[0]);
	else if (stk_size == 3)
		sort_three(&stack);
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
