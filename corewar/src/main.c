/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/29 21:43:24 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm_types.h"
#include "vm_protos.h"

static void	load_players(t_list const *p_d, t_list **players, t_list **progs)
{
	void			*data;
	size_t			fsize;
	size_t			progsize;
	t_player_data	*player;
	char			*prog_name;

	while (p_d != NULL)
	{
		player = (t_player_data *)(p_d->content);
		data = get_file_data(player->filename, &fsize);
		prog_name = ((t_header *)data)->prog_name;
		*players = ft_lstnew(create_player(player->id, prog_name),
							sizeof(t_player));
		*progs = ft_lstnew(get_program(data, fsize, &progsize), progsize);
		p_d = p_d->next;
	}
}

int			main(int ac, char const **av)
{
	t_args_data	args;
	t_vm		vm;
	t_list		*players_data;
	t_list		*players;
	t_list		*programs;
	int			i;

	i = 0;
	if (!param_vm(&args, ac, av))
		return (1);
	vm.dump_cycles = args.dump_cycles;
	players_data = args.players_data;
	load_players(players_data, &players, &programs);
	init_vm(&vm, args.players_nb, players, programs);
	while (i++ != args.dump_cycles)
	{
		if (vm_step(&vm) == 1)
		{
			ft_putstr("le joueur ");
			ft_putnbr(vm.last_living_player->id);
			ft_putstr("(");
			ft_putstr(vm.last_living_player->name);
			ft_putstr(") a gagne\n");
			return (0);
		}
	}
	dump_data(vm.arena.mem, sizeof(vm.arena), 64);
	return (0);
}
