/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/09/01 19:40:59 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Pareil que ldi, mais n’applique aucun modulo aux adresses.
// Modifiera, par contre, le carry
void			lldi(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	t_arg_type		type[2];
	int				ops[2];
	int				data;
	size_t			addr;
	size_t			reg;

	instr = &proc->instruction;
	reg = instr->params[2];
	type[0] = instr->args_types[0];
	type[1] = instr->args_types[1];
	if (check_param(instr->args_types[2], reg) == false
		|| check_param(type[0], instr->params[0]) == false
		|| check_param(type[1], instr->params[1]) == false)
	{
		move_pc(&proc->pc, instr->size);
		return ;
	}
	ops[0] = get_value(type[0], instr->params[0], &vm->arena, proc->registers);
	ops[1] = get_value(type[1], instr->params[1], &vm->arena, proc->registers);
	addr = proc->pc + ops[0] + ops[1];
	data = loadmem(&vm->arena, REG_SIZE, addr);
	ltob(&data, REG_SIZE);
	storeg(&proc->registers[reg], &data, sizeof(data));
	proc->carry = proc->pc != 0;
	move_pc(&proc->pc, instr->size);
}
