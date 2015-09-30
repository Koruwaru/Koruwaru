/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:24:57 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/30 21:24:45 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"
#include "op.h"

#include <stdio.h> // CACA

static char		flag_from_code(char code)
{
	static const t_arg_type	tab[] = {T_REG, T_DIR, T_IND};

	return (tab[(int)code - 1]);
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
//		printf("REF: %x - ITS: %x\n", op->args_types[i], get_param_code(ocp, i));
		param_type = flag_from_code(get_param_code(ocp, i));
		if ((param_type & op->args_types[i]) == 0)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static void		init_args_types(t_instruction *instr, t_op const *op,
							t_arena const *a, size_t *pc)
{
	char				ocp;
	size_t				i;

	i = 0;
	if (op->ocp == 1)
	{
		ocp = a->mem[*pc];
		while (i < op->nb_params)
		{
			instr->args_types[i] = flag_from_code(get_param_code(ocp, i));
			i++;
		}
		move_pc(pc, 1);
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
}

void			load_instr(t_process *proc, t_arena const *a)
{
	t_instruction	*instr;
	t_op const		*op_tmp;
	size_t			pc;
	char			ocp;

	pc = proc->pc;
	instr = &proc->instruction;
	ft_bzero(instr, sizeof(*instr));
	instr->opcode = a->mem[pc];
	op_tmp = get_op(instr->opcode);
	move_pc(&pc, 1);
	ocp = a->mem[pc];
	if (op_tmp == NULL || verif_ocp(op_tmp, ocp) == false)
	{
//		printf("Fils de pute %x\n", instr->opcode);
		instr->opcode = 0;
		instr->nb_params = 0;
		instr->size = 1;
		proc->remaining_cycles = 1;
	}
	else
	{
		instr->nb_params = op_tmp->nb_params;
		init_args_types(instr, op_tmp, a, &pc);
		printf("INSTR %s %x %x %x\n", op_tmp->name, instr->args_types[0], instr->args_types[1], instr->args_types[2]);
		proc->remaining_cycles = op_tmp->cycles;
	}
}
