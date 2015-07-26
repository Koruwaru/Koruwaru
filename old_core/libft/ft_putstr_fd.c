/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 21:49:53 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 18:43:56 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	char	*tmp;
	int		i;

	tmp = (char *)s;
	i = 0;
	while (tmp[i] != '\0')
	{
		ft_putchar_fd(tmp[i], fd);
		i++;
	}
	return (i);
}
