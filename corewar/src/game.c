/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 14:45:41 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/04 15:56:07 by tmielcza         ###   ########.fr       */
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
		printf("Coucou! --------------------------- \n");
		vm->cycles = 0;
		if (vm->nb_lives >= NBR_LIVE || vm->checks >= MAX_CHECKS)
			vm->cycles_to_die -= CYCLE_DELTA;
		vm->nb_lives = 0;
		tmp = &vm->processes;
		while (*tmp != NULL)
		{
			proc = (*tmp)->content;
//			printf("lives: %d\n", proc->nb_lives);
			if (proc->nb_lives == 0)
			{
				printf("He died! %d \n", vm->cycles_to_die);
				ft_lstpop(tmp, ft_lstfree);
			}
			else
			{
				proc->nb_lives = 0;
				tmp = &(*tmp)->next;
			}
		}
	}
}

int			vm_step(t_vm *vm)
{
	t_list		*tmp;
	t_process	*proc;

	tmp = vm->processes;
	while (tmp != NULL)
	{
		proc = tmp->content;
		if (--proc->remaining_cycles == 0)
		{
			exec_instr(vm, proc);
			load_instr(proc, &vm->arena);
		}
		tmp = tmp->next;
	}
	vm_check(vm);
	if (vm->processes == NULL)
	{
		printf("Finito !\n");
		exit(0);
	}
	return (0);
}
