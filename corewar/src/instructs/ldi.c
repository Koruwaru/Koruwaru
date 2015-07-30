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

static int	get_value(t_arg_type type, t_uint value, t_arena const *a,
						t_register const *regs)
{
	if (type == T_DIR) // direct is mem addr
	{
		return (loadmem(a, REG_SIZE, value)); // is it ok ?
	}
	else if (type == T_IND) // indirect is a number
	{
		ltob(&value, sizeof(value)); // is value big or little endian ?
		return (value);
	}
	else // T_REG, it's a register number
	{
		// TODO what can I do if reg number is false ?
		return (loadreg(&regs[value]));
	}
}

// TODO check if value is little or big endiant ^^^^^^^
// ca prend 2 index
// et 1 registre, additionne les 2 premiers, traite ca comme une adresse,
// y lit une valeur de la taille d’un registre et la met dans le 3eme.
void		ldi(t_vm *vm, t_process *process)
{
	t_arg_type	type;
	int			a;
	int			b;
	int			data;
	size_t		reg;

	// first test if the register exist
	reg = process->instruction.params[2];
	ltob(&reg, sizeof(reg));
	if (reg >= REG_NUMBER)
		return ; // if not then abort

	// get all data: a and b
	type = get_param_type(process->instruction.params_types, 0);
	a = get_value(type, process->instruction.params[0], &vm->arena,
					process->registers);
	type = get_param_type(process->instruction.params_types, 1);
	b = get_value(type, process->instruction.params[1], &vm->arena,
					process->registers);

	// read data from 0xb(a + b) addr
	data = loadmem(&vm->arena, REG_SIZE, a + b); // big endian
	ltob(&data, REG_SIZE); // register are little endian

	// store the data in the appropriate register
	storeg(&process->registers[reg], &data, REG_SIZE, 0);
}
