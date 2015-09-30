/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 23:45:00 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/30 17:16:41 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

t_bool		check_param(t_arg_type type, int value)
{
	if (type == T_DIR || type == T_IND)
		return (true);
	if (type == T_REG && value <= REG_NUMBER && value > 0)
		return (true);
	return (false);
}

int			long_get_value(t_arg_type type, int value, t_arena const *a,
					t_process const *proc)
{
	int		val;

	if (type == T_IND)
	{
		val = loadmem(a, REG_SIZE, proc->pc + value);
		ltob(&val, sizeof(val));
		return (val);
	}
	if (type == T_DIR)
		return (value);
	return (loadreg(&proc->registers[value]));
}

int			get_value(t_arg_type type, int value, t_arena const *a,
					t_process const *proc)
{
	int		val;

	if (type == T_IND)
	{
		val = loadmem(a, REG_SIZE, proc->pc + (value % IDX_MOD));
		ltob(&val, sizeof(val));
		return (val);
	}
	if (type == T_DIR)
		return (value);
	return (loadreg(&proc->registers[value]));
}
