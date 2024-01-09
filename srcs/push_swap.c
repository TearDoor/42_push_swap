/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 02:49:35 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
void	sort_three(t_stack **stacks)
{
	int		max_i;

	max_i = max_num_index(stacks[0]);
	if (max_i == 0)
		op_ra(stacks);
	else if (max_i == 1)
		op_rra(stacks);
	if (!ft_stack_issorted(stacks[0]))
		op_sa(stacks);
}

/* calculates the cost for all elements to rotate to the top
positive means rotations and negative means reverse rotations*/
void	ft_stack_rotate_cost(t_stack *stack)
{
	int	i;
	int	size;
	int	mid;

	i = 0;
	size = ft_stack_size(stack);
	mid = size / 2;
	while (stack)
	{
		if (i <= mid)
			stack->cost.own = i;
		else
			stack->cost.own = i - size;
		stack = stack->next;
		i++;
	}
	return ;
}

int	ft_compare(int a, int b, char mode)
{
	if (a > b)
	{
		if (mode == 'l')
			return (1);
		else
			return (0);
	}
	else
	{
		if (mode == 's')
			return (1);
		else
			return (0);
	}
}

t_stack	*ft_stack_most(t_stack *stack, char mode, char item)
{
	t_stack	*most;

	most = stack;
	while (stack)
	{
		if (item == 'n')
		{
			if (ft_compare(stack->num, most->num, mode))
				most = stack;
		}
		else if (item == 'c')
		{
			if (ft_compare(stack->cost.total, most->cost.total, mode))
				most = stack;
		}
		stack = stack->next;
	}
	return (most);
}

int	ft_find_target_atob(t_stack *stack_b, int nbr)
{
	t_stack	*target;
	t_stack	*curr;

	target = NULL;
	curr = stack_b;
	while (curr)
	{
		if (curr->num < nbr)
		{
			if (!target)
				target = curr;
			else if (curr->num > target->num)
				target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		target = ft_stack_most(stack_b, 'l', 'n');
	return (target->cost.own);
}

int	ft_find_target_btoa(t_stack *stack_a, int nbr)
{
	t_stack	*target;
	t_stack	*curr;

	target = NULL;
	curr = stack_a;
	while (curr)
	{
		if (curr->num > nbr)
		{
			if (!target)
				target = curr;
			else if (curr->num < target->num)
				target = curr;
		}
		curr = curr->next;
	}
	if (!target)
		target = ft_stack_most(stack_a, 's', 'n');
	return (target->cost.own);
}

void	ft_stack_total_cost(t_stack *src_stack, t_stack *dst_stack, char src)
{
	int	dst_cost;

	ft_stack_rotate_cost(src_stack);
	ft_stack_rotate_cost(dst_stack);
	while (src_stack)
	{
		if (src == 'a')
			dst_cost = ft_find_target_atob(dst_stack, src_stack->num);
		else if (src == 'b')
			dst_cost = ft_find_target_btoa(dst_stack, src_stack->num);
		src_stack->cost.dst = dst_cost;
		src_stack->cost.total = abs(src_stack->cost.own) + abs(dst_cost);
		src_stack = src_stack->next;
	}
	return ;
}

int	ft_rotate_ab(int rot, char s, t_stack **stacks)
{
	while (rot != 0)
	{
		if (rot > 0)
		{
			if (s == 'a')
				op_ra(stacks);
			else if (s == 'b')
				op_rb(stacks);
			rot -= 1;
		}
		else if (rot < 0)
		{
			if (s == 'a')
				op_rra(stacks);
			else if (s == 'b')
				op_rrb(stacks);
			rot += 1;
		}
	}
	return rot;
}

void	ft_rotate_to_top(int rot_a, int rot_b, t_stack **stacks)
{
	while (!(rot_a == 0 && rot_b == 0))
	{
		if (rot_a > 0 && rot_b > 0)
		{
			op_rr(stacks);
			rot_a -= 1;
			rot_b -= 1;
		}
		else if (rot_a < 0 && rot_b < 0)
		{
			op_rrr(stacks);
			rot_a += 1;
			rot_b += 1;
		}
		else
		{
			rot_a = ft_rotate_ab(rot_a, 'a', stacks);
			rot_b = ft_rotate_ab(rot_b, 'b', stacks);
		}
	}
}

void	ft_b_to_a(t_stack **stacks)
{
	t_stack	*cheapest;
	
	while (stacks[1])
	{
		ft_stack_total_cost(stacks[1], stacks[0], 'b');
		cheapest = ft_stack_most(stacks[1], 's', 'c');
		ft_rotate_to_top(cheapest->cost.dst, cheapest->cost.own, stacks);
		op_pa(stacks);
	}
}

void	ft_a_to_b(t_stack **stacks)
{
	int		size;
	t_stack	*cheapest;
	
	size = ft_stack_size(stacks[0]);
	while (size > 3)
	{
		ft_stack_total_cost(stacks[0], stacks[1], 'a');
		cheapest = ft_stack_most(stacks[0], 's', 'c');
		ft_rotate_to_top(cheapest->cost.own, cheapest->cost.dst, stacks);
		op_pb(stacks);
		size -= 1;
	}
}

void	sort_big(t_stack **stack_pair, int stk_size)
{
	int		i;
	t_stack	*smallest;

	i = 0;
	while (stk_size > 3 && !ft_stack_issorted(stack_pair[0]) && i < 2)
	{
		op_pb(stack_pair);
		stk_size -= 1;
		i++;
	}
	ft_a_to_b(stack_pair);
	sort_three(&stack_pair[0]);
	ft_b_to_a(stack_pair);
	smallest = ft_stack_most(stack_pair[0], 's', 'n');
	ft_stack_rotate_cost(stack_pair[0]);
	ft_rotate_to_top(smallest->cost.own, 0, stack_pair);
	return ;
}


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
