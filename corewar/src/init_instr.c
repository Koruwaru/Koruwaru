/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 17:17:43 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"
#include "op.h"

static size_t	read_param(size_t size, t_arena const *a, size_t pc)
{
	char	data[4];

	ft_bzero(data, 4);
	while (size-- != 0)
	{
		data[size] = a->mem[pc];
		pc = (pc + 1) % MEM_SIZE;
	}
	return (*(size_t *)data);
}

static void		init_params(t_instruction *instr, t_op const *op,
							t_arena const *a, size_t pc)
{
	size_t		i;
	t_arg_type	param_type;
	size_t		param_s;

	i = 0;
	pc = (pc + 1) % MEM_SIZE;
	instr->size = 1;
	if (op->ocp == 1)
	{
		instr->params_types = a->mem[pc];
		pc = (pc + 1) % MEM_SIZE;
		instr->size += 1;
	}
	while (i < instr->nb_params)
	{
		param_type = instr->params_types & (0x03 << (i * 2));
		if (param_type & T_REG)
			param_s = 1;
		else if (param_type & T_DIR)
			param_s = 2;
		else if (param_type & T_IND)
		{
			if (op->ind_size == 0)
				param_s = 4;
			else
				param_s = 2;
		}
		instr->size += param_s;
		instr->params[i] = read_param(param_s, a, pc);
		pc = (pc + 1) % MEM_SIZE;
		i++;
	}
}

void			load_instr(t_process *proc, t_arena const *a, size_t pc)
{
	t_instruction	*instr;
	t_op const		*op_tmp;

	instr = &proc->instruction;
	instr->opcode = a->mem[pc];
	op_tmp = get_op(instr->opcode);
	if (op_tmp == NULL)
	{
		instr->opcode = 0;
		instr->nb_params = 0;
		proc->remaining_cycles = 1;
	}
	else
	{
		instr->nb_params = op_tmp->nb_params;
		proc->remaining_cycles = op_tmp->cycles;
		init_params(instr, op_tmp, a, pc);
	}
}
