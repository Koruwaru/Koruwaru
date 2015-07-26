/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:14:05 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:13:52 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*ft_reverse(char *src)
{
	char	*tmp;
	int		i;
	int		cnt;

	i = ft_strlen(src) - 1;
	cnt = 0;
	tmp = (char *)malloc(sizeof(char*) * (i + 1));
	while (i > 0)
	{
		tmp[cnt] = src[i];
		cnt++;
		i--;
	}
	tmp[cnt] = src[i];
	cnt++;
	tmp[cnt] = '\0';
	return (tmp);
}

static char		*ft_unsignedhex_reso(unsigned int n, int i, char *dest, int rs)
{
	while (n)
	{
		rs = n % 16;
		n = n / 16;
		if (rs < 10)
			dest[i] = '0' + rs;
		else if (rs == 10)
			dest[i] = 'a';
		else if (rs == 11)
			dest[i] = 'b';
		else if (rs == 12)
			dest[i] = 'c';
		else if (rs == 13)
			dest[i] = 'd';
		else if (rs == 14)
			dest[i] = 'e';
		else if (rs == 15)
			dest[i] = 'f';
		i++;
	}
	dest[i] = '\0';
	dest = ft_reverse(dest);
	return (dest);
}

void			ft_unsignedhex(unsigned int n)
{
	int		i;
	char	*dest;
	int		rs;

	i = 0;
	rs = 0;
	dest = (char *)malloc(sizeof(char *) * 13);
	if (n == 0)
		ft_putchar('0');
	dest = ft_unsignedhex_reso(n, i, dest, rs);
	ft_putstr(dest);
}
