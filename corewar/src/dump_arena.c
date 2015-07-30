/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 13:40:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 16:58:08 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "vm_protos.h"

void		ctoah(unsigned char byte, char ret[2])
{
	int					i;
	static const char	hexa[] = "0123456789abcdef";

	i = byte % 16;
	ret[1] = hexa[i];
	i = (byte - i) / 16;
	ret[0] = hexa[i];
}

void		dump_data(void const *d, size_t size, size_t line_s)
{
	char		buff[2];
	char const	*tmp;
	void const	*end;
	size_t		i;

	line_s--;
	i = 0;
	tmp = d;
	end = tmp + size;
	while (tmp != end)
	{
		if (i > line_s)
		{
			ft_putstr("\n");
			i = 0;
		}
		ctoah(*tmp, buff);
		write(1, buff, sizeof(buff));
		ft_putstr(" ");
		i++;
		tmp++;
	}
	ft_putstr("\n");
}
