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
void			ldi(t_vm *vm, t_process *process)
{
	t_arg_type	type[2];
	int			a;
	int			b;
	int			data;
	size_t		reg;

	// first test if the result register exist
	reg = process->instruction.params[2];
	type[0] = get_param_type(process->instruction.params_types, 0);
	type[1] = get_param_type(process->instruction.params_types, 1);
	if (!check_param(get_param_type(process->instruction.params_types, 2), reg)
		|| check_param(type[0], process->instruction.params[0]) == false
		|| check_param(type[1], process->instruction.params[1]) == false)
	{
		move_pc(&process->pc, process->instruction.size);
		return ;
	}

	// get all data: a and b
	a = get_value(type[0], process->instruction.params[0], &vm->arena,
					process->registers);
	b = get_value(type[1], process->instruction.params[1], &vm->arena,
					process->registers);

	// read data from 0xb(a + b) addr
	data = loadmem(&vm->arena, REG_SIZE, (a + b) % IDX_MOD); // big endian
	ltob(&data, REG_SIZE); // register are little endian

	// store the data in the appropriate register
	storeg(&process->registers[reg], &data, REG_SIZE);

	// move after execution
	move_pc(&process->pc, process->instruction.size);
}
