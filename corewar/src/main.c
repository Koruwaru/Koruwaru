/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/22 17:14:56 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm_types.h"
#include "vm_protos.h"

int main(int ac, char **av)
{
	void	*data;
	size_t	fsize;
	size_t	progsize;
	t_vm	vm;
	t_list	*players;
	t_list	*programs;

	int max = ft_atoi(av[2]);

	int i = 0;

	(void)ac;
	data = get_file_data(av[1], &fsize);
	players = ft_lstnew(create_player(-1, ((t_header *)data)->prog_name), sizeof(t_player));
	programs = ft_lstnew(get_program(data, fsize, &progsize), progsize);

//	data = get_file_data(av[2], &fsize);
//	players->next = ft_lstnew(create_player(-2, ((header_t *)data)->prog_name), sizeof(t_player));
//	programs->next = ft_lstnew(get_program(data, fsize, &progsize), progsize);

	init_vm(&vm, 1, players, programs);

	while (i++ != max)
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
