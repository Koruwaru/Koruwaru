/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 13:40:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/03 15:38:47 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "vm_protos.h"

static void	ctoah(unsigned char byte, char ret[2])
{
	int					i;
	static const char	hexa[] = "0123456789abcdef";

	i = byte % 16;
	ret[1] = hexa[i];
	i = (byte - i) / 16;
	ret[0] = hexa[i];
}

static void	addr(unsigned int addr, char ret[9])
{
	ret[0] = '0';
	ret[1] = 'x';
	ctoah((addr >> 8) & 0xFF, ret + 2);
	ctoah((addr >> 0) & 0xFF, ret + 4);
	ret[6] = ' ';
	ret[7] = ':';
	ret[8] = ' ';
}

void		dump_data(void const *d, size_t size, size_t line_s)
{
	char		buff[2];
	char		a[9];
	char const	*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	tmp = d;
	while (i < size)
	{
		j = 0;
		addr(i, a);
		write(1, a, sizeof(a));
		while (j != line_s && i + j != size)
		{
			ctoah(*tmp, buff);
			write(1, buff, sizeof(buff));
			ft_putstr(" ");
			j++;
			tmp++;
		}
		i += line_s;
		ft_putstr("\n");
	}
}
