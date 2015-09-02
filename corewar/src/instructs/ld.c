/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 15:19:03 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/02 23:41:11 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		ld(t_vm *vm, t_process *p)
{
	t_instruction	*instr;
	t_arg_type		a0t;
	int				val;
	int				p0;

	instr = &p->instruction;
	p0 = instr->params[0];
	a0t = instr->args_types[0];
	if (check_param(T_REG, instr->params[1]) == true)
	{
		if (a0t == T_IND)
		{
			p0 = p0 % IDX_MOD;
		}
		val = get_value(a0t, p0, &vm->arena, p);
		storeg(p->registers + instr->params[1], &val, sizeof(val));
		p->carry = true;
	}
	move_pc(&p->pc, instr->size);
}
