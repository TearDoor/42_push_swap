/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:32:13 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/09 20:35:58 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_rotate_ab(int rot, char s, t_stack **stacks)
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
	return (rot);
}

static void	ft_rotate_to_top(int rot_a, int rot_b, t_stack **stacks)
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

static void	ft_b_to_a(t_stack **stacks)
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

static void	ft_a_to_b(t_stack **stacks, int *lis, int lis_size)
{
	int		size;
	int		max_size;
	t_stack	*cheapest;

	size = ft_stack_size(stacks[0]);
	max_size = 3;
	if (lis_size > max_size)
		max_size = lis_size;
	while (size > 3)
	{
		ft_stack_total_cost(stacks[0], stacks[1], 'a');
		cheapest = ft_stack_a_cheapest(stacks[0], lis, lis_size);
		cheapest = ft_stack_most(stacks[0], 's', 'c');
		ft_rotate_to_top(cheapest->cost.own, cheapest->cost.dst, stacks);
		op_pb(stacks);
		size -= 1;
	}
}

void	sort_big(t_stack **stack_pair, int stk_size)
{
	int		i;
	int		*num;
	int		*lis;
	int		lis_size;
	t_stack	*smallest;

	i = 0;
	while (stk_size > 3 && !ft_stack_issorted(stack_pair[0]) && i < 2)
	{
		op_pb(stack_pair);
		stk_size -= 1;
		i++;
	}
	num = stack_to_array(stack_pair[0], stk_size);
	lis = find_lis(num, stk_size, &lis_size);
	ft_a_to_b(stack_pair, lis, lis_size);
	if (stk_size == 3)
		sort_three(stack_pair);
	ft_b_to_a(stack_pair);
	smallest = ft_stack_most(stack_pair[0], 's', 'n');
	ft_stack_rotate_cost(stack_pair[0]);
	ft_rotate_to_top(smallest->cost.own, 0, stack_pair);
	free(num);
	free(lis);
	return ;
}
