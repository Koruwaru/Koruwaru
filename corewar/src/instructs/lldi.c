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
void		lldi(t_vm *vm, t_process *process)
{
	t_arg_type	type;
	int			a;
	int			b;
	size_t		addr;
	int			data;
	size_t		reg;

	// first test if the result register exist
	reg = process->instruction.params[2];
	ltob(&reg, sizeof(reg));
	if (reg >= REG_NUMBER)
	{
		move_pc(&process->pc, process->instruction.size);
		return ; // if not then abort after moving forward
	}

	// get all data: a and b
	type = get_param_type(process->instruction.params_types, 0);
	if (check_param(type, process->instruction.params[0]) == false)
	{
		move_pc(&process->pc, process->instruction.size);
		return ; // if not then abort after moving forward
	}
	a = get_value(type, process->instruction.params[0], &vm->arena,
					process->registers);

	type = get_param_type(process->instruction.params_types, 1);
	if (check_param(type, process->instruction.params[1]) == false)
	{
		move_pc(&process->pc, process->instruction.size);
		return ; // if not then abort after moving forward
	}
	b = get_value(type, process->instruction.params[1], &vm->arena,
					process->registers);

	// read data from 0xb(a + b) addr)
	addr = a + b;
	if (addr >= MEM_SIZE)
	{
		process->carry = false;
		move_pc(&process->pc, process->instruction.size);
		return ;
	}
	data = loadmem(&vm->arena, REG_SIZE, addr); // big endian
	ltob(&data, REG_SIZE); // register are little endian

	// store the data in the appropriate register
	storeg(&process->registers[reg], &data, REG_SIZE, 0);

	// change the carry
	process->carry = true;

	// move after execution
	move_pc(&process->pc, process->instruction.size);
}
