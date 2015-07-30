/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storeg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 14:02:56 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/30 20:27:12 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

void		storeg(t_register *reg, void const *data, size_t size, size_t pc)
{
	size_t	pcend;
	size_t	i;

	i = 0;
	pcend = pc;
	move_pc(&pcend, (int)size - 1);
	ft_bzero(reg->data, REG_SIZE);
	while (pc != pcend)
	{
		reg->data[i] = ((char *)data)[pc];
		move_pc(&pc, 1);
		i++;
	}
}

int			loadreg(t_register const *reg)
{
	return (*(int *)reg->data);
}
