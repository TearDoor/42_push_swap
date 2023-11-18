/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:59:25 by tkok-kea          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/18 18:05:45 by tkok-kea         ###   ########.fr       */
=======
/*   Updated: 2023/11/15 01:00:10 by tkok-kea         ###   ########.fr       */
>>>>>>> 10c7a9b4624c07fc28f883dd6d90fa593263c524
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_error(void);
t_stack	*init_stack(int argc, char **argv);

/* functions for initializing and clearing stack */
t_stack	*ft_stacknew(int n);
void	ft_stackaddback(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

/* to check stack has duplicates or is sorted*/
int	stack_isdup(t_stack *stack);
int	stack_issorted(t_stack *stack);

/* operations */
void	op_sa(t_stack **a);

#endif