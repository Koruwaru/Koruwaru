/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 16:06:29 by tmielcza         ###   ########.fr       */
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

	(void)ac;
	data = get_file_data(av[1], &fsize);
	players = ft_lstnew(create_player(1, ((header_t *)data)->prog_name), sizeof(t_player));
	programs = ft_lstnew(get_program(data, fsize, &progsize), progsize);
	init_vm(&vm, 1, players, programs);
	dump_data(vm.arena.mem, MEM_SIZE, 64);
	return (0);
}
