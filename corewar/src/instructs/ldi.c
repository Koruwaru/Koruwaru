/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:48:10 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:48:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// ca prend 2 index et 1 registre,
// additionne les 2 premiers, traite ca comme une adresse,
// y lit une valeur de la taille d’un registre et la met dans le 3eme.
void			ldi(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	t_arg_type		type[2];
	int				ops[2];
	int				data;
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
	data = loadmem(&vm->arena, REG_SIZE, (ops[0] + ops[1]) % IDX_MOD);
	ltob(&data, REG_SIZE);
	storeg(&proc->registers[reg], &data, REG_SIZE);
	move_pc(&proc->pc, instr->size);
}
