#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static void	verif_live(t_vm *vm, t_process *proc)
{
	t_player const	*p;

	p = vm->last_living_player;
	printf("Last living player: %s, %zu\n", p ? p->name : "NULL", p ? p->id : 0);
	printf("Process: lives [%zu], pc [%zu]\n", proc->nb_lives, proc->pc);
	printf("---------------------------");
}

void		live_tests(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;

	instr = &proc->instruction;

	vm->players[0] = *create_player(3, "Pute");
	vm->players[1] = *create_player(5, "Caca");

	verif_live(vm, proc);

	set_instr(instr, 1, 0, ARGS(1, 0, 0));
	live(vm, proc);
	verif_live(vm, proc);

	set_instr(instr, 1, 0, ARGS(3, 0, 0));
	live(vm, proc);
	verif_live(vm, proc);

	set_instr(instr, 1, 0, ARGS(5, 0, 0));
	live(vm, proc);
	verif_live(vm, proc);

	set_instr(instr, 1, 0, ARGS(6, 0, 0));
	live(vm, proc);
	verif_live(vm, proc);
}
