/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 00:28:23 by crenault          #+#    #+#             */
/*   Updated: 2015/09/03 19:15:27 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

void	fork_(t_vm *vm, t_process *process)
{
	t_process		*new;
	t_instruction	*instr;
	int				p1;

	instr = &process->instruction;
	new = dup_process(process);
	new->nb_lives = 0;
	p1 = get_value(instr->args_types[0], instr->params[0], &vm->arena, process);
	move_pc(&new->pc, p1 % IDX_MOD);
//	printf("fork. new pc : %d %d %d\n", new->pc, p1, process->pc);
	load_instr(new, &vm->arena);
	//new->remaining_cycles--;
	ft_lstadd(&vm->processes, ft_lstcreate(new, sizeof(t_process)));
	move_pc(&process->pc, process->instruction.size);
}
