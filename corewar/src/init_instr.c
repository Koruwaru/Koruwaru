/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/03 18:06:12 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"
#include "op.h"

static int	read_param(size_t size, t_arena const *a, size_t pc)
{
	int		any;
	short	short_indirect;
	char	*data;
	size_t	tmp;

	any = 0;
	short_indirect = 0;
	tmp = 0;
	if (size == 2)
		data = &short_indirect;
	else
		data = &any;
	while (tmp != size)
	{
		data[tmp] = a->mem[pc];
		move_pc(&pc, 1);
		tmp++;
	}
//	for (int i = 0; i < size; i++) printf("-%d-", data[i]);
//	printf("\n");
	ltob(data, size);
	if (size == 2)
		return (short_indirect);
	else
		return (any);
}

static size_t	get_param_size(t_arg_type param_type, t_op const *op)
{
	size_t		param_s;

	param_s = 0;
	if (param_type == T_REG)
		param_s = 1;
	else if (param_type == T_IND)
		param_s = 2;
	else if (param_type == T_DIR)
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
	size_t				i;
	size_t				param_s;
	char				ocp;
	static t_arg_type	tab[] = {T_REG, T_DIR, T_IND};

	move_pc(&pc, 1);
	instr->size = 1;
	i = 0;
	if (op->ocp == 1)
	{
		ocp = a->mem[pc];
		while (i < op->nb_params)
		{
			instr->args_types[i] = tab[get_param_code(ocp, i) - 1];
			i++;
		}
		move_pc(&pc, 1);
		instr->size += 1;
	}
	else
	{
		while (i < op->nb_params)
		{
			instr->args_types[i] = op->args_types[i];
			i++;
		}
	}
	i = 0;
	while (i < instr->nb_params)
	{
		param_s = get_param_size(instr->args_types[i], op);
//		printf("Param ! -> %x %d\n", instr->args_types[i], param_s);
		instr->size += param_s;
		instr->params[i] = read_param(param_s, a, pc);
//		printf("A param: %d\n", instr->params[i]);
		move_pc(&pc, param_s);
		i++;
	}
}

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
//		printf("check : <%x> <%x> %d == %d \n", ocp, param_type, op->args_types[i], op->ocp);
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
	int				ocp;

	pc = proc->pc;
	instr = &proc->instruction;
	instr->opcode = a->mem[pc];
	op_tmp = get_op(instr->opcode);
	move_pc(&pc, 1);
	ocp = a->mem[pc];
//	printf("op = %d, tmp = %p\n", instr->opcode, op_tmp);
	if (op_tmp == NULL || verif_ocp(op_tmp, ocp) == false)
	{
		instr->opcode = 0;
		instr->nb_params = 0;
		instr->size = 1;
		proc->remaining_cycles = 1;
//		printf("Bad!\n");
	}
	else
	{
		instr->nb_params = op_tmp->nb_params;
		proc->remaining_cycles = op_tmp->cycles;
		init_params(instr, op_tmp, a, proc->pc);
//		printf("Good! size -> %d\n", instr->size);
	}
}
