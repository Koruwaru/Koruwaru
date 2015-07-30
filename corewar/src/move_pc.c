/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefw_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 17:52:39 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/30 17:53:29 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		move_pc(size_t *pc, int steps)
{
	if (steps < 0)
	{
		steps = (steps % MEM_SIZE) + MEM_SIZE;
	}
	*pc = (*pc + steps) % MEM_SIZE;
}
