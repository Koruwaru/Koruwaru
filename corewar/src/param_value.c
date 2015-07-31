/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:48:10 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:48:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

t_bool		check_param(t_arg_type type, t_uint value)
{
	if (type == T_DIR || type == T_IND)
		return (true);
	if (type == T_REG && value < REG_NUMBER)
		return (true);
	return (false);
}

int			get_value(t_arg_type type, t_uint value, t_arena const *a,
						t_register const *regs)
{
	if (type == T_IND)
		return (loadmem(a, REG_SIZE, value));
	if (type == T_DIR)
		return (value);
	return (loadreg(&regs[value]));
}
