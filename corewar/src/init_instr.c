/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/30 17:48:46 by tmielcza         ###   ########.fr       */
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

static size_t	get_param_size(char ocp, t_op const *op, int param_nb)
{
	t_arg_type	param_type;
	size_t		param_s;

	param_s = 0;
	if (op->ocp == 0)
	{
		param_s = op->args_types[param_nb];
	}
	param_type = ocp & (0x03 << (param_nb * 2));
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
	return (param_s);
}

static void		init_params(t_instruction *instr, t_op const *op,
							t_arena const *a, size_t pc)
{
	size_t		i;
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
		param_s = get_param_size(instr->params_types, op, i);
		instr->size += param_s;
		instr->params[i] = read_param(param_s, a, pc);
		pc = (pc + 1) % MEM_SIZE;
		i++;
	}
}

t_bool			verif_ocp(t_op const *op, char ocp)
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
		param_type = ocp & (0x03 << (params_nb * 2));
		if ((param_type & op->args_types[i]) == 0)
		{
			return (false);
		}
	}
	return (true);
}

void			load_instr(t_process *proc, t_arena const *a, size_t pc)
{
	t_instruction	*instr;
	t_op const		*op_tmp;

	instr = &proc->instruction;
	instr->opcode = a->mem[pc];
	op_tmp = get_op(instr->opcode);
	if (op_tmp == NULL || verif_ocp(op_tmp, instr->opcode))
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
