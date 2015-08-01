/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:30:20 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/30 18:48:16 by tmielcza         ###   ########.fr       */
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

	offset = nb_players ? MEM_SIZE / nb_players : 0;
	vm->nb_players = nb_players;
	vm->processes = NULL;
	i = 0;
	ft_bzero(vm->arena.mem, MEM_SIZE);
	while (players != NULL && progs != NULL)
	{
		vm->players[i] = *(t_player *)players->content;
		size = min(progs->content_size, offset);
		ft_memcpy(vm->arena.mem + offset * i, progs->content, size);
		proc = create_process(vm->players[i].id, offset * i);
		load_instr(proc, &vm->arena);
		ft_lstadd(&vm->processes, ft_lstcreate(proc, sizeof(t_process)));
		players = players->next;
		progs = progs->next;
		i++;
	}
	vm->last_living_player = NULL;
}
