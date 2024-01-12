/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:43:12 by tkok-kea          #+#    #+#             */
/*   Updated: 2024/01/11 20:57:31 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* stores number of rotations needed to be on top of stack */
typedef struct s_cost
{
	int	own;
	int	dst;
	int	total;
}	t_cost;

typedef struct s_stack
{
	int				num;
	t_cost			cost;
	struct s_stack	*next;
}	t_stack;

int		*find_lis(int *num, int num_size, int *lis_max);
int		*stack_to_array(t_stack *stack, int size);
int		ft_stack_size(t_stack *stack);
void	ft_stack_rotate_cost(t_stack *stack);
t_stack	*ft_stack_most(t_stack *stack, char mode, char item);
void	ft_stack_total_cost(t_stack *src_stack, t_stack *dst_stack);

/* functions for initializing and clearing stack */
t_stack	*init_stack(int argc, char **argv);
t_stack	*ft_stacknew(int n);
void	ft_stackaddback(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

/* to check stack has duplicates or is sorted*/
int		ft_stack_isdup(t_stack *stack);
int		ft_stack_issorted(t_stack *stack);

/* sorting for different sizes */
void	sort_three(t_stack **stacks);
void	sort_big(t_stack **stack_pair, int stk_size);

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

/* utility functions */
void	ft_error(void);
int		ft_abs(int num);
int		ft_compare(int a, int b, char mode);
int		ft_array_search(int *arr, int size, int num);

/* some functions for debugging */
void	ft_printstack(t_stack *stack);
void	ft_print_both_stacks(t_stack **stacks);

#endif