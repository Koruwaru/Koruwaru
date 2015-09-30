/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:30:20 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/30 17:02:02 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm_protos.h"

static size_t	min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

void			init_vm(t_vm *vm, size_t nb_players, t_list const *players,
					t_list const *progs)
{
	size_t		i;
	size_t		offset;
	size_t		size;
	t_process	*proc;

	ft_bzero(vm, sizeof(*vm));
	offset = nb_players ? MEM_SIZE / nb_players : 0;
	vm->nb_players = nb_players;
	vm->next_proc_id = 1;
	i = 0;
	ft_bzero(vm->arena.mem, sizeof(vm->arena.mem));
	while (players != NULL && progs != NULL)
	{
		vm->players[i] = *(t_player *)players->content;
		size = min(progs->content_size, offset);
		ft_memcpy(vm->arena.mem + offset * i, progs->content, size);
		proc = create_process(vm->players[i].id, offset * i);
		proc->id = vm->next_proc_id++;
		load_instr(proc, &vm->arena);
		ft_lstadd(&vm->processes, ft_lstcreate(proc, sizeof(t_process)));
		players = players->next;
		progs = progs->next;
		vm->cycles_to_die = CYCLE_TO_DIE;
		i++;
	}
}
