/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:59:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/08 18:44:31 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
t_stack	*init_stack(int argc, char **argv);

/* functions for initializing and clearing stack */
t_stack	*ft_stacknew(int n);
void	ft_stackaddback(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

/* to check stack has duplicates or is sorted*/
int		stack_isdup(t_stack *stack);
int		stack_issorted(t_stack *stack);

/* operations */
void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);

/* some functions for debugging */
void	ft_print_both_stacks(t_stack *a, t_stack *b);

#endif