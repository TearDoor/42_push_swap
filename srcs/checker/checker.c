/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:37:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/13 01:49:23 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*ops;

	stack_a = init_stack(argc, argv);
	ops = get_next_line(0);
	if (!ops)
	{
		if (ft_stack_issorted(stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}

	free(stack_a);
	return (0);
}