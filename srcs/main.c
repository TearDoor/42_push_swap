/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:59 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/11/05 21:27:38 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error()
{	
	write(2, "Error\n", 6);
	exit(1);
}

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

t_stack	*split_string(char *argv)
{
	int		i;
	int		new_num;
	t_stack	*stack_a;
	char	**n_str;

	stack_a = NULL;
	n_str = ft_split(argv, ' ');
	i = 0;
	while (n_str[i])
	{
		new_num = ft_atoi_check(n_str[i]);
		i++;
	}
	//free(n_str);
	return (stack_a);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	
	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		stack_a = split_string(argv[1]);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = init_stack(argc, argv);
	
	return (0);
}
