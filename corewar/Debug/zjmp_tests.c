/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 17:23:10 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 15:01:01 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

static void	verif_zjmp(t_vm *vm, t_process *proc, size_t old_pc)
{
	(void)vm;
	if (proc->carry == true && proc->instruction.params[0] % MEM_SIZE == proc->pc)
	{
		printf("ok carry = true, params[0] %% MEM_SIZE == proc->pc\n");
	}
	else if (proc->carry == false && old_pc == proc->pc)
	{
		printf("ok carry = false, old_pc == proc->pc\n");
	}
	else
	{
		printf("error proc->pc: %zu + param: %u != %zu\n",
				old_pc, proc->instruction.params[0], proc->pc);
	}
	printf("---------------------------\n");
}

void		zjmp_tests(t_vm *vm, t_process *proc)
{
	size_t			old_pc;
	t_instruction	*instr;

	instr = &proc->instruction;

	printf( HEADER("zjmp tests:\n") );
	printf( COM("No players\n") );

	printf( COM("zjump carry: true to 10 %% MEM_SIZE\n") );
	proc->carry = true;
	old_pc = proc->pc;
	set_instr(instr, 1, 0, ARGS(10, 0, 0));
	zjmp(vm, proc);
	verif_zjmp(vm, proc, old_pc);

	printf( COM("zjump carry: true to 300 %% MEM_SIZE\n") );
	proc->carry = true;
	old_pc = proc->pc;
	set_instr(instr, 1, 0, ARGS(300, 0, 0));
	zjmp(vm, proc);
	verif_zjmp(vm, proc, old_pc);

	printf( COM("zjump carry: false to 1 %% MEM_SIZE\n") );
	proc->carry = false;
	old_pc = proc->pc;
	set_instr(instr, 1, 0, ARGS(1, 0, 0));
	zjmp(vm, proc);
	verif_zjmp(vm, proc, old_pc);

	printf( COM("zjump carry: false to 60000 %% MEM_SIZE\n") );
	proc->carry = false;
	old_pc = proc->pc;
	set_instr(instr, 1, 0, ARGS(60000, 0, 0));
	zjmp(vm, proc);
	verif_zjmp(vm, proc, old_pc);
}
