/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/05 22:23:18 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_assign_cost(t_stack **stack)
{
	int	i;
	int size;
	int	mid;
	t_stack	*curr;

	i = 0;
	size = ft_stack_size(*stack);
	mid = size / 2;
	curr = *stack;
	while (curr)
	{
		if (i <= mid)
			curr->cost = i;
		else
			curr->cost = i - size;
		curr = curr->next;
		i++;
	}
	return ;
}

void	sort_big(t_stack *stack_a, int stk_size)
{
	t_stack	*stack_pair[2];
	int		i;

	stack_pair[0] = stack_a;
	stack_pair[1] = NULL;
	i = 0;
	while (stk_size > 3 && !ft_stack_issorted(stack_pair[0]) && i < 2)
	{
		op_pb(stack_pair);
		stk_size -= 1;
		i++;
	}
	ft_stack_assign_cost(&stack_pair[0]);
	ft_printstack(stack_pair[0]);
	return ;
}

/* returns the index of the biggest number in a stack */
int	max_num_index(t_stack *stack)
{
	int	max;
	int	i;
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
void	sort_three(t_stack *stack)
{
	int	max_i;

	max_i = max_num_index(stack);
	if (max_i == 0)
		op_ra(&stack);
	else if (max_i == 1)
		op_rra(&stack);
	if (!ft_stack_issorted(stack))
		op_sa(&stack);
}

static void	sort(t_stack *stack)
{
	int		stk_size;

	stk_size = ft_stack_size(stack);
	if (stk_size == 2)
		op_sa(&stack);
	else if (stk_size == 3)
		sort_three(stack);
	else
		sort_big(stack, stk_size);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	if (!stack_a || ft_stack_isdup(stack_a))
		ft_error();
	if (ft_stack_issorted(stack_a))
		return (0);
	sort(stack_a);
	ft_stackclear(&stack_a);
	return (0);
}
