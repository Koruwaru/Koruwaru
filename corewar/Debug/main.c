/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/01 18:49:19 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft.h"
#include "vm_types.h"
#include "vm_protos.h"
#include <stdlib.h>
#include <stdio.h>

t_uint	create_ocp(t_arg_type a, t_arg_type b, t_arg_type c)
{
	return (a << 6 | b << 4 | c << 2);
}

int main()
{
	t_vm		vm;
	t_process	*proc;

	proc = create_process(2, 400);
	init_vm(&vm, 0, NULL, NULL);

	live_tests(&vm, proc);
	ld_tests(&vm, proc);
	st_tests(&vm, proc);
	add_tests(&vm, proc);
	sub_tests(&vm, proc);
	and_tests(&vm, proc);
	or_tests(&vm, proc);
	xor_tests(&vm, proc);

//	zjmp_tests(&vm, proc);
	ldi_tests(&vm, proc);
	sti_tests(&vm, proc);
	fork__tests(&vm, proc);
	lld_tests(&vm, proc);
	lldi_tests(&vm, proc);

	return (0);
}