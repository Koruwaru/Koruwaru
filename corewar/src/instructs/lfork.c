/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/09/06 17:38:47 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

// Ca signifie long-fork, pour pouvoir fourcher de la paille à une distance
// de 15 mètres, exactement comme son opcode. Pareil qu’un fork sans modulo à
// l’adresse.
void		lfork(t_vm *vm, t_process *process)
{
	int			pc;
	t_process	*new;

	new = dup_process(process);
	new->cycles_since_live = 0;
	pc = loadmem(&vm->arena, sizeof(pc), process->instruction.params[0]);
	ltob(&pc, sizeof(pc));
	move_pc(&new->pc, pc);
	ft_lstadd(&vm->processes, ft_lstcreate(new, sizeof(t_process)));
	move_pc(&process->pc, process->instruction.size);
}
