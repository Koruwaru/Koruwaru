/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:08:24 by crenault          #+#    #+#             */
/*   Updated: 2015/09/07 18:35:59 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void	zjmp(t_vm *vm, t_process *process)
{
	(void)vm;
	if (process->carry == true)
	{
		move_pc(&process->pc, process->instruction.params[0] % IDX_MOD);
	}
	else
	{
		move_pc(&process->pc, process->instruction.size);
	}
}
