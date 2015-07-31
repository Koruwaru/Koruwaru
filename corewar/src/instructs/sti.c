/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:08:32 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:08:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Prend un registre, et deux index (potentiellement des registres).
// Additionne les deux derniers, utilise cette somme comme une adresse
// ou sera copiée la valeur du premier paramètre.
void		sti(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	t_arg_type		type[2]; // for the two last params
	int				ops[2];
	size_t			reg;
	int				value;

	instr = &proc->instruction;
	reg = instr->params[0];
	// TODO check if get_param_type works like this
	// get last params types to check them
	type[0] = get_param_type(instr->args_types[1], 1);
	type[1] = get_param_type(instr->args_types[2], 2);
	if (check_param(get_param_type(instr->args_types[0], 0), reg) == false
		|| check_param(type[0], instr->params[1]) == false
		|| check_param(type[1], instr->params[2]) == false)
	{
		move_pc(&proc->pc, instr->size);
		return ;
	}
	// get all values
	ops[0] = get_value(type[0], instr->params[1], &vm->arena, proc->registers);
	ops[1] = get_value(type[1], instr->params[2], &vm->arena, proc->registers);
	value = get_value(T_REG, reg, &vm->arena, proc->registers);
	// copy register at pc position
	stomem(&vm->arena, &value, REG_SIZE, ops[0] + ops[1]);
	move_pc(&proc->pc, proc->instruction.size);
}
