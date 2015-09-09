/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/09/09 19:03:01 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void			lldi(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	t_arg_type		type[2];
	int				ops[2];
	int				data;
	size_t			reg;

	instr = &proc->instruction;
	reg = instr->params[2];
	type[0] = instr->args_types[0];
	type[1] = instr->args_types[1];
	if (check_param(instr->args_types[2], reg)
		&& check_param(type[0], instr->params[0])
		&& check_param(type[1], instr->params[1]))
	{
		ops[0] = long_get_value(type[0], instr->params[0], &vm->arena, proc);
		ops[1] = long_get_value(type[1], instr->params[1], &vm->arena, proc);
		data = loadmem(&vm->arena, REG_SIZE, proc->pc + ops[0] + ops[1]);
		ltob(&data, REG_SIZE);
		storeg(&proc->registers[reg], &data, sizeof(data));
		proc->carry = proc->pc != 0;
	}
	move_pc(&proc->pc, instr->size);
}
