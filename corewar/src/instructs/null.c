/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 17:28:21 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 11:17:41 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		null(t_vm *vm, t_process *process)
{
	(void)vm;
	move_pc(&process->pc, process->instruction.size);
}
