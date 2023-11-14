/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:25:55 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/10/20 15:13:28 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	len;

	len = nelem * elsize;
	if (nelem != 0 && elsize > UINT_MAX / nelem)
		return (NULL);
	ptr = (void *)malloc(nelem * elsize);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}