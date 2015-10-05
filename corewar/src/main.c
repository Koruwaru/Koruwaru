/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/05 20:19:36 by tmielcza         ###   ########.fr       */
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
		ft_lstadd(players,
				ft_lstnew(create_player(player->id, prog_name),
						sizeof(t_player)));
		ft_lstadd(progs,
				ft_lstnew(get_program(data, fsize, &progsize), progsize));
		p_d = p_d->next;
	}
}

static void	print_victory(t_vm const *vm)
{
	ft_putstr("le joueur ");
	ft_putnbr(vm->last_living_player->id);
	ft_putstr("(");
	ft_putstr(vm->last_living_player->name);
	ft_putstr(") a gagne\n");
}

int			main(int ac, char const **av)
{
	t_args_data	args;
	t_vm		vm;
	t_list		*players_data;
	t_list		*players;
	t_list		*programs;

	players = NULL;
	programs = NULL;
	players_data = NULL;
	ft_bzero(&args, sizeof(args));
	if (!param_vm(&args, ac, av) || args.players_nb == 0)
		return (1);
	if (args.players_nb > MAX_PLAYERS)
		return (ft_putstr_fd("Too much of the players.\n", 2), 1);
	players_data = args.players_data;
	load_players(players_data, &players, &programs);
	init_vm(&vm, args.players_nb, players, programs);
	vm.dump_cycles = args.dump_cycles;
	while (!vm_step(&vm))
		;
	if (vm.dump_cycles > 0 && vm.dump_cycles <= vm.vm_cycles)
		dump_data(vm.arena.mem, sizeof(vm.arena), 64);
	else
		print_victory(&vm);
	return (0);
}
