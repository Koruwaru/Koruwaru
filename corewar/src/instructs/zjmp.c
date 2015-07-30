/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:06:30 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 18:07:14 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void	zjmp(t_vm *vm, t_process *process)
{
	(void)vm;
	if (process->carry == true)
	{
		set_pc(&process->pc, process->instruction.params[0]);
	}
}
