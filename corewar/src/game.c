/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:45:41 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/08 19:14:20 by tmielcza         ###   ########.fr       */
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
//	printf("%d %d \n", vm->cycles, vm->cycles_to_die);
	if (vm->cycles >= vm->cycles_to_die)
	{
//		printf("Coucou! --------------------------- \n");
		tmp = &vm->processes;
		while (*tmp != NULL)
		{
			proc = (*tmp)->content;
//			printf("(%d) cycles_since_live: %d <%d>\n", proc->id, proc->cycles_since_live, vm->cycles_to_die);
			if (proc->cycles_since_live >= vm->cycles_to_die)
			{
//				printf("(%d) died! %d <%d> \n", proc->id, proc->cycles_since_live, vm->cycles_to_die);
				ft_lstpop(tmp, ft_lstfree);
			}
			else
			{
				tmp = &(*tmp)->next;
			}
		}
		if (vm->nb_lives >= NBR_LIVE || vm->checks >= MAX_CHECKS)
			vm->cycles_to_die -= CYCLE_DELTA;
		vm->cycles = 0;
		vm->nb_lives = 0;
	}
}

int			vm_step(t_vm *vm)
{
	t_list		*tmp;
	t_process	*proc;

	vm->actual_cycle++;
	printf("Now cycle: %zu --------------------------------------\n", vm->actual_cycle);
	tmp = vm->processes;
	while (tmp != NULL)
	{
		proc = tmp->content;
		proc->cycles_since_live++;
		if (--proc->remaining_cycles == 0)
			exec_instr(vm, proc);
		tmp = tmp->next;
	}
	tmp = vm->processes;
	while (tmp != NULL)
	{
		proc = tmp->content;
		if (proc->remaining_cycles == 0)
			load_instr(proc, &vm->arena);
		tmp = tmp->next;
	}
	vm_check(vm);
	if (vm->processes == NULL)
	{
//		printf("Finito !\n");
		exit(0);
	}
	return (0);
}
