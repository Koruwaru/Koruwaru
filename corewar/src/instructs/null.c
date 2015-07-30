/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: TODO: retieve old 'Created' info         #+#    #+#             */
/*   Updated: 2015/07/30 23:06:30 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		null(t_vm *vm, t_process *process)
{
	(void)vm;
	move_pc(&process->pc, process->instruction.size);
}
