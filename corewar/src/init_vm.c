/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:30:20 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/27 18:49:53 by tmielcza         ###   ########.fr       */
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
	size_t	i;
	size_t	offset;
	size_t	size;

	offset = MEM_SIZE / nb_players;
	vm->nb_players = nb_players;
	i = 0;
	while (players != NULL)
	{
		vm->players[i] = *(t_player *)players->content;
		players = players->next;
		i++;
	}
	vm->last_living_player = NULL;
	ft_bzero(vm->arena.mem, MEM_SIZE);
	vm->processes = NULL;
	i = 0;
	while (progs != NULL)
	{
		size = min(progs->content_size, offset);
		ft_memcpy(vm->arena.mem + offset * i, progs->content, size);
		ft_lstadd(&vm->processes, ft_lstcreate(
					create_process(NULL, offset * i, 0), sizeof(t_process)));
		i++;
	}
}
