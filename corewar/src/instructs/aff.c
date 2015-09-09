/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/09/09 19:42:21 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include <unistd.h>

void		aff(t_vm *vm, t_process *process)
{
	t_arg_type	type;
	int			param;
	int			value;

	type = process->instruction.args_types[0];
	param = process->instruction.params[0];
	if (check_param(type, param))
	{
		value = get_value(type, param, &vm->arena, process) % 256;
		write(1, &value, 1);
	}
	move_pc(&process->pc, process->instruction.size);
}
