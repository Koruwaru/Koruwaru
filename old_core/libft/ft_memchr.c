/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:02:36 by jyim              #+#    #+#             */
/*   Updated: 2013/11/24 19:42:55 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	chr;

	dest = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*dest == c)
			return ((void *)dest);
		n--;
		dest++;
	}
	return (NULL);
}
