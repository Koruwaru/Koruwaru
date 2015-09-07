/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 15:02:59 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/07 22:21:02 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

#include <stdio.h> // GROSSE BITE DE MERDE

void		exec_instr(t_vm *vm, t_process *proc)
{
	char				opcode;
	static t_instrf		tabs[] =
		{
			null, live, ld, st, add, sub, and_, or_,
			xor_, zjmp, ldi, sti, fork_, lld, lldi, lfork, aff
		};

	t_op *op = get_op(proc->instruction.opcode);
	char *name = op ? op->name : "null";
	t_instruction *i = &proc->instruction;
	opcode = proc->instruction.opcode;
	if (opcode != 0)
		load_instr(proc, &vm->arena);
	proc->instruction.opcode = opcode;
	printf("(%d) do instr %s|%d| - %d %d %d <%d> [:%d/%x]\n", proc->id, name, proc->instruction.opcode, i->params[0], i->params[1], i->params[2], proc->carry, proc->pc, proc->pc);
	tabs[(int)proc->instruction.opcode](vm, proc);
}
