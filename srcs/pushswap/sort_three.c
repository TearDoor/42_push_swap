/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:24:17 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/03/24 15:10:55 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns the index of the biggest number in a stack */
static int	max_num_index(t_stack *stack)
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
		op_ra(stacks, 1);
	else if (max_i == 1)
		op_rra(stacks, 1);
	if (!ft_stack_issorted(stacks[0]))
		op_sa(stacks, 1);
}
