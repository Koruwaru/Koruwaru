/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 19:50:24 by tmielcza         ###   ########.fr       */
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

static void		get_params(t_instruction *instr, t_op const *op,
							t_arena const *a, size_t pc)
{
	size_t		i;
	t_arg_type	ocp;
	size_t		param_s;

	i = 0;
	pc = (pc + 1) % MEM_SIZE;
	instr->params_types = a->mem[pc];
	pc = (pc + 1) % MEM_SIZE;
	while (i < instr->nb_params)
	{
		ocp = instr->params_types & (0x03 << (i * 2));
		if (ocp & T_REG)
			param_s = 1;
		else if (ocp & T_DIR)
			param_s = 2;
		else if (ocp & T_IND)
		{
			if (op->ind_size == 0)
				param_s = 4;
			else
				param_s = 2;
		}
		instr->params[i] = read_param(1, a, pc);
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
		instr->opcode = op_tmp->op_code;
		instr->nb_params = op_tmp->nb_params;
		proc->remaining_cycles = op_tmp->cycles;
	}
}
