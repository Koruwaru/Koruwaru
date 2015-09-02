/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:45:41 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/02 20:08:25 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

#include <stdio.h> // ATTENTIER IL FAUT ENLEVONS

static void	vm_check(t_vm *vm)
{
	t_list		**tmp;
	t_process	*proc;

	++vm->cycles;
	if (vm->cycles >= vm->cycles_to_die)
	{
		vm->cycles = 0;
		if (vm->nb_lives >= NBR_LIVE || vm->checks >= MAX_CHECKS)
			vm->cycles_to_die -= CYCLE_DELTA;
		vm->nb_lives = 0;
		tmp = &vm->processes;
		while (*tmp != NULL)
		{
			proc = (*tmp)->content;
			if (proc->nb_lives == 0)
				ft_lstpop(tmp, ft_lstfree);
			proc->nb_lives = 0;
			if (*tmp != NULL)
				tmp = &(*tmp)->next;
		}
	}
}

int			vm_step(t_vm *vm)
{
	t_list		**tmp;
	t_process	*proc;

	tmp = &vm->processes;
	while (*tmp != NULL)
	{
		proc = (*tmp)->content;
		if (--proc->remaining_cycles == 0)
		{
			exec_instr(vm, proc);
			load_instr(proc, &vm->arena);
		}
//		printf("remaining = %d\n", proc->remaining_cycles);
		tmp = &(*tmp)->next;
	}
	vm_check(vm);
	return (000);
}
