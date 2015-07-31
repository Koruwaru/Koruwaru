/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 00:28:23 by crenault          #+#    #+#             */
/*   Updated: 2015/07/31 00:28:23 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

// Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée
// un nouveau processus, qui hérite des différents états de son père,
// à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
void	fork_(t_vm *vm, t_process *process)
{
	size_t		pc;
	t_process	*new;

	new = dup_process(process);
	new->nb_lives = 0;
	pc = loadmem(&vm->arena, sizeof(int), process->instruction.params[0]);
	move_pc(&new->pc, pc % IDX_MOD);
	ft_lstadd(&vm->processes, ft_lstcreate(new, sizeof(t_process)));
	move_pc(&process->pc, process->instruction.size);
}
