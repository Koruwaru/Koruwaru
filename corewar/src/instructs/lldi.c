/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:11:27 by crenault         ###   ########.fr       */
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
	// TODO check if get_param_type works like this
	type[0] = get_param_type(instr->args_types[0], 0);
	type[1] = get_param_type(instr->args_types[1], 1);
	if (check_param(get_param_type(instr->args_types[2], 2), reg) == false
		|| check_param(type[0], instr->params[0]) == false
		|| check_param(type[1], instr->params[1]) == false)
	{
		move_pc(&proc->pc, instr->size);
		return ;
	}
	ops[0] = get_value(type[0], instr->params[0], &vm->arena, proc->registers);
	ops[1] = get_value(type[1], instr->params[1], &vm->arena, proc->registers);
	addr = ops[0] + ops[1];
	if (check_param(T_REG, addr) == true)
	{
		proc->carry = false;
		move_pc(&proc->pc, proc->instruction.size);
		return ;
	}
	data = loadmem(&vm->arena, REG_SIZE, addr);
	ltob(&data, REG_SIZE);
	storeg(&proc->registers[reg], &data, REG_SIZE);
	proc->carry = true;
	move_pc(&proc->pc, instr->size);
}
