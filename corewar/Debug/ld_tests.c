#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static void	verif(t_vm *vm, t_process *proc)
{
	t_player const	*p;

	p = vm->last_living_player;
	printf("Registers: ");
	for (int i = 0; i < REG_NUMBER; i++)
		printf("[%d]", loadreg(proc->registers + i));
	printf("\n");
	printf("Process: carry [%d], pc [%zu]\n", proc->carry, proc->pc);
	printf("---------------------------\n");
}

void		ld_tests(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	int		mem = 10;
	int		reg = 20;
	int		dir = 30;
	int		pos = 35;
	int		nreg = 2;

	instr = &proc->instruction;

	printf( HEADER("LD tests:\n") );
	printf( COM("[%d] in mem at pos [%d];\n"
				"[%d] in reg [%d];\n"
				"[%d] direct;\n"),
			mem, pos, reg, nreg, dir);

	ltob(&mem, sizeof(mem));
	ltob(&reg, sizeof(reg));
	ltob(&dir, sizeof(dir));
	stomem(&vm->arena, &mem, sizeof(mem), pos);
	dump_data(&vm->arena, MEM_SIZE, 8);
	storeg(proc->registers + 1, &reg, sizeof(reg), 0);
	verif(vm, proc);

	printf( COM("LD %d 2\n"), pos);
	set_instr(instr, 2, 2, OCP2(T_IND, T_REG), ARG2(pos, 2));
	ld(vm, proc);
	verif(vm, proc);
}
