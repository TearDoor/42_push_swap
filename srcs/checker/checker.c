/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:37:56 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/12 14:33:16 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);

	free(stack_a);
	return (0);
}