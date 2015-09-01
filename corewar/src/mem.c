/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:21:01 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/01 19:24:57 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		stomem(t_arena *a, void const *data, size_t data_s, size_t pc)
{
	size_t	pcend;
	size_t	i;

	i = 0;
	pcend = pc;
	move_pc(&pcend, (int)data_s);
	while (pc != pcend)
	{
		a->mem[pc] = ((char *)data)[i];
		move_pc(&pc, 1);
		i++;
	}
}

int			loadmem(t_arena const *a, size_t size, size_t pc)
{
	size_t	i;
	int		val;

	i = 0;
	val = 0;
	move_pc(&pc, 0);
	while (i < size)
	{
		((char *)&val)[i] = a->mem[pc];
		move_pc(&pc, 1);
		i++;
	}
	return (val);
}
