/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:32:13 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/03/24 15:10:48 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate_ab(int rot, char s, t_stack **stacks)
{
	while (rot != 0)
	{
		if (rot > 0)
		{
			if (s == 'a')
				op_ra(stacks, 1);
			else if (s == 'b')
				op_rb(stacks, 1);
			rot -= 1;
		}
		else if (rot < 0)
		{
			if (s == 'a')
				op_rra(stacks, 1);
			else if (s == 'b')
				op_rrb(stacks, 1);
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
			op_rr(stacks, 1);
			rot_a -= 1;
			rot_b -= 1;
		}
		else if (rot_a < 0 && rot_b < 0)
		{
			op_rrr(stacks, 1);
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
		ft_stack_total_cost(stacks[1], stacks[0]);
		cheapest = ft_stack_most(stacks[1], 's', 'c');
		ft_rotate_to_top(cheapest->cost.dst, cheapest->cost.own, stacks);
		op_pa(stacks, 1);
	}
}

static void	ft_a_to_b(t_stack **stacks, int *size, int *lis, int lis_size)
{
	int	max_size;

	max_size = 3;
	if (lis_size > max_size)
		max_size = lis_size;
	while (*size > max_size)
	{
		while (ft_arr_binary_search(lis, lis_size, (stacks[0])->num))
			op_ra(stacks, 1);
		op_pb(stacks, 1);
		*size -= 1;
	}
}

void	sort_big(t_stack **stack_pair, int stk_size)
{
	int		*num;
	int		*lis;
	int		lis_size;
	t_stack	*smallest;

	num = stack_to_array(stack_pair[0], stk_size);
	lis = find_lis(num, stk_size, &lis_size);
	ft_a_to_b(stack_pair, &stk_size, lis, lis_size);
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
