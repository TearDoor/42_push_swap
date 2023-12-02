/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/02 16:34:59 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	stack_a = init_stack(argc, argv);
	if (!stack_a || stack_isdup(stack_a))
		ft_error();
	if (stack_issorted(stack_a))
		ft_putendl_fd("Is sorted", 1);
	op_sa(&stack_a);
	ft_printstack(stack_a);
	ft_stackclear(&stack_a);
	stack_a = NULL;
	return (0);
}
