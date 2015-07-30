/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:31:38 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:31:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

// TODO to change, don't need pc here
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
