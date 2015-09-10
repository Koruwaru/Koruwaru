/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 15:02:59 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:31:21 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		exec_instr(t_vm *vm, t_process *proc)
{
	char				opcode;
	t_instrf			instr;
	t_op const			*op;
	static t_instrf		tabs[] = {
		null, live, ld, st, add, sub, and_, or_,
		xor_, zjmp, ldi, sti, fork_, lld, lldi, lfork, aff
	};

	op = get_op(proc->instruction.opcode);
	opcode = proc->instruction.opcode;
	if (opcode != 0)
	{
		init_params(&proc->instruction, op, &vm->arena, proc->pc);
	}
	proc->instruction.opcode = opcode;
	instr = tabs[(int)proc->instruction.opcode];
	instr(vm, proc);
}
