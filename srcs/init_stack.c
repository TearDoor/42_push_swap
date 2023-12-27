/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:12:27 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/27 18:51:53 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi_check(char *s)
{
	int				neg;
	long long int	nbr;

	nbr = 0;
	neg = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg = -1;
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			ft_error();
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if ((nbr * neg) > INT_MAX || (nbr * neg) < INT_MIN)
		ft_error();
	return (nbr * neg);
}

static void	free_strings(char **str)
{
	int	i;

	if (!*str)
		return ;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

/*splits arguments passed as a string into numbers */
t_stack	*split_string(char *argv)
{
	int		i;
	char	**n_str;
	int		new_num;
	t_stack	*stack_a;

	stack_a = NULL;
	n_str = ft_split(argv, ' ');
	i = 0;
	while (n_str[i])
	{
		new_num = ft_atoi_check(n_str[i]);
		ft_stackaddback(&stack_a, ft_stacknew(new_num));
		i++;
	}
	free_strings(n_str);
	return (stack_a);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		new_num;

	stack_a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		stack_a = split_string(argv[1]);
	else
	{
		i = 1;
		while (argv[i])
		{
			new_num = ft_atoi_check(argv[i]);
			ft_stackaddback(&stack_a, ft_stacknew(new_num));
			i++;
		}
	}
	return (stack_a);
}
