/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 11:46:25 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm_types.h"
#include "vm_protos.h"

t_uint	create_ocp(t_arg_type a, t_arg_type b, t_arg_type c)
{
	return (a << 6 | b << 4 | c << 2);
}

int main()
{
	t_vm	vm;
	t_process *proc;

	proc = create_process(2, 400);
	init_vm(&vm, 0, NULL, NULL);
	dump_data(vm.arena.mem, MEM_SIZE, 64);
	return (0);
}
