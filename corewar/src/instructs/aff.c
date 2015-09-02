/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/09/02 23:44:26 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include <unistd.h>

// L’opcode est 10 en hexadécimal. Il y a un octet de codage des paramètres,
// même si c’est un peu bête car il n’y a qu’un paramètre, qui est un registre,
// dont le contenu est interprété comme la valeur ASCII d’un caractère
// à afficher sur la sortie standard. Ce code est modulo 256.
void		aff(t_vm *vm, t_process *process)
{
	t_arg_type	type;
	int			param;
	int			value;

	type = process->instruction.args_types[0];
	param = process->instruction.params[0];
	if (process->instruction.args_types[0] == T_REG
		&& check_param(type, param) == false)
	{
		move_pc(&process->pc, process->instruction.size);
		return ;
	}
	value = get_value(type, param, &vm->arena, process) % 256;
	write(1, &value, 1);
	move_pc(&process->pc, process->instruction.size);
}
