/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 15:19:03 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 19:21:45 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

#include <stdio.h> // VIRER

void		ld(t_vm *vm, t_process *p)
{
	t_instruction	*instr;
	t_arg_type		a1t;
	int				val;
	int				p0;

	instr = &p->instruction;
	p0 = instr->params[0];
	a1t = get_param_type(instr->params_types, 0);
	if (check_param(T_REG, instr->params[1]) == true)
	{
		if (a1t == T_IND)
		{
			p0 = (p0 % MEM_SIZE);
			if (p0 < 0)
			{
				p0 += MEM_SIZE;
			}
		}
		printf("%d %d %d %d %d \n", instr->params_types, a1t, p0,
			   get_param_type(instr->params_types, 1),
			   get_param_type(instr->params_types, 2));
		val = get_value(a1t, p0, &vm->arena, p->registers);
		ltob(&val, sizeof(val));
		storeg(p->registers + instr->params[1], &val, sizeof(val));
		p->carry = true;
	}
	move_pc(&p->pc, instr->size);
}
