/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:42:37 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/10/04 17:00:44 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_isalpha('4'));

	return (0);
}
*/