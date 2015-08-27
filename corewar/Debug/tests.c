/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 16:03:20 by tmielcza          #+#    #+#             */
/*   Updated: 2015/08/27 18:05:40 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"
#include "vm_protos.h"
#include "libft.h"

static void	reset(t_vm *vm, t_process *proc)
{
	ft_bzero(&vm->arena, sizeof(vm->arena));
	vm->last_living_player = NULL;
	ft_bzero(proc, sizeof(*proc));
}

void		unit_tests(test_func *funcs, t_vm *vm, t_process *proc, size_t funcs_nb, char const *instr_name)
{
	printf("%s:", instr_name);
	for (size_t i = 0; i < funcs_nb; i++) {
		reset(vm, proc);
		if (funcs[i](vm, proc)) {
			printf(GOOD("⭕️ "));
		} else {
			printf(ERR("❌ "));
		}
	}
	printf("\n");
}
