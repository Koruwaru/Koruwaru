/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:45:41 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:32:24 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

static void	vm_check(t_vm *vm)
{
	t_list		**tmp;
	t_process	*proc;

	++vm->cycles;
	if (vm->cycles >= vm->cycles_to_die)
	{
		tmp = &vm->processes;
		while (*tmp != NULL)
		{
			proc = (*tmp)->content;
			if (proc->cycles_since_live >= vm->cycles_to_die)
			{
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
		exit(0);
	return (0);
}
