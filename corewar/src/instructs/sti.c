/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:08:32 by crenault          #+#    #+#             */
/*   Updated: 2015/09/03 18:05:42 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Prend un registre, et deux index (potentiellement des registres).
// Additionne les deux derniers, utilise cette somme comme une adresse
// ou sera copiée la valeur du premier paramètre.
void		sti(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	t_arg_type		type[2];
	int				ops[2];
	size_t			reg;
	int				val;

	instr = &proc->instruction;
	reg = instr->params[0];
	type[0] = instr->args_types[1];
	type[1] = instr->args_types[2];
	if (check_param(instr->args_types[0], reg) == false
		|| check_param(type[0], instr->params[1]) == false
		|| check_param(type[1], instr->params[2]) == false)
	{
		move_pc(&proc->pc, instr->size);
		return ;
	}
	ops[0] = get_value(type[0], instr->params[1], &vm->arena, proc);
	ops[1] = get_value(type[1], instr->params[2], &vm->arena, proc);
	val = get_value(T_REG, reg, &vm->arena, proc);
	ltob(&val, sizeof(val));
	stomem(&vm->arena, &val, REG_SIZE, proc->pc + (ops[0] + ops[1]) % IDX_MOD);
	move_pc(&proc->pc, proc->instruction.size);
}
