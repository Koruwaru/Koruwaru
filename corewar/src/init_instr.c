/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:54:07 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"
#include "op.h"

static t_bool	verif_ocp(t_op const *op, char ocp)
{
	size_t		i;
	t_arg_type	param_type;
	size_t		params_nb;

	if (op->ocp != 1)
	{
		return (true);
	}
	params_nb = op->nb_params;
	i = 0;
	while (i < params_nb)
	{
		param_type = get_param_code(ocp, i);
		if ((param_type & op->args_types[i]) == 0)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void			load_instr(t_process *proc, t_arena const *a)
{
	t_instruction	*instr;
	t_op const		*op_tmp;
	size_t			pc;
	char			ocp;

	pc = proc->pc;
	instr = &proc->instruction;
	instr->opcode = a->mem[pc];
	op_tmp = get_op(instr->opcode);
	move_pc(&pc, 1);
	ocp = a->mem[pc];
	if (op_tmp == NULL || verif_ocp(op_tmp, ocp) == false)
	{
		instr->opcode = 0;
		instr->nb_params = 0;
		instr->size = 1;
		proc->remaining_cycles = 1;
	}
	else
	{
		instr->nb_params = op_tmp->nb_params;
		proc->remaining_cycles = op_tmp->cycles;
	}
}
