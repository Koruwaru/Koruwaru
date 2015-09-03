/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 00:00:53 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/03 18:08:20 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

#include <stdio.h>

void		st(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	int				val;
	int				p0;
	int				p1;

	instr = &proc->instruction;
	p0 = instr->params[0];
	p1 = instr->params[1];
	if (check_param(instr->args_types[0], p0)
		|| check_param(instr->args_types[1], instr->params[1]))
	{
		val = get_value(instr->args_types[0], p0, &vm->arena, proc);
		if (instr->args_types[1] == T_REG)
		{
			storeg(&proc->registers[p1], &val, sizeof(val));
		}
		else
		{
			stomem(&vm->arena, &val, sizeof(val), proc->pc + (p1 % IDX_MOD));
		}
	}
	move_pc(&proc->pc, instr->size);
}
