/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 15:02:59 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/02 18:27:55 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		exec_instr(t_vm *vm, t_process *proc)
{
	static t_instrf		tabs[] =
		{
			null, live, ld, st, add, sub, and_, or_,
			xor_, zjmp, ldi, sti, fork_, lld, lldi, lfork, aff
		};

	tabs[(int)proc->instruction.opcode](vm, proc);
}
