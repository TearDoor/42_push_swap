/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:59:25 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/05 21:56:08 by tkok-kea         ###   ########.fr       */
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
	int				cost;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
t_stack	*init_stack(int argc, char **argv);
int		*find_lis(int *num, int num_size, int *lis_max);
int		ft_stack_size(t_stack *stack);

/* functions for initializing and clearing stack */
t_stack	*ft_stacknew(int n);
void	ft_stackaddback(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

/* to check stack has duplicates or is sorted*/
int		ft_stack_isdup(t_stack *stack);
int		ft_stack_issorted(t_stack *stack);

/* operations */
void	op_sa(t_stack **stacks);
void	op_sb(t_stack **stacks);
void	op_ss(t_stack **stacks);
void	op_pa(t_stack **stacks);
void	op_pb(t_stack **stacks);
void	op_ra(t_stack **stacks);
void	op_rb(t_stack **stacks);
void	op_rr(t_stack **stacks);
void	op_rra(t_stack **stacks);
void	op_rrb(t_stack **stacks);
void	op_rrr(t_stack **stacks);

/* some functions for debugging */
void	ft_printstack(t_stack *stack);
void	ft_print_both_stacks(t_stack **stacks);

#endif