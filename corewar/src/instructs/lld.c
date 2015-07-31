/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 00:32:08 by crenault          #+#    #+#             */
/*   Updated: 2015/07/31 00:32:08 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Signifie long-load, donc son opcode est évidemment 13. C’est la même chose
// que ld, mais sans % IDX_MOD. Modifie le carry.
void		lld(t_vm *vm, t_process *process)
{
	t_instruction	*instr;
	t_arg_type		type;
	int				a;
	int				b;
	int				data;
	size_t			reg;

	instr = &process->instruction;
	// first test if the result register exist
	reg = instr->params[2];
	if (!check_param(get_param_type(instr->args_types[2], 2), reg))
	{
		move_pc(&process->pc, instr->size);
		return ; // if not then abort after moving forward
	}

	// get all data: a and b
	type = get_param_type(instr->args_types[0], 0);
	if (check_param(type, instr->params[0]) == false)
	{
		move_pc(&process->pc, instr->size);
		return ; // if not then abort after moving forward
	}
	a = get_value(type, instr->params[0], &vm->arena,
					process->registers);

	type = get_param_type(instr->args_types[1], 1);
	if (check_param(type, instr->params[1]) == false)
	{
		move_pc(&process->pc, instr->size);
		return ; // if not then abort after moving forward
	}
	b = get_value(type, instr->params[1], &vm->arena,
					process->registers);

	// read data from 0xb(a + b) addr
	data = loadmem(&vm->arena, REG_SIZE, a + b); // big endian
	ltob(&data, REG_SIZE); // register are little endian

	// store the data in the appropriate register
	storeg(&process->registers[reg], &data, REG_SIZE);

	// move after execution
	move_pc(&process->pc, instr->size);
}
