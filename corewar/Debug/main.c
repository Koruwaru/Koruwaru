/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/08/27 16:34:36 by tmielcza         ###   ########.fr       */
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
//	zjmp_tests(&vm, proc);

	return (0);
}
