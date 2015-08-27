#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

t_bool		test1(t_vm *vm, t_process *proc) {
	int		val = 30;
	int		test;

	storeg(proc->registers + 1, &val, sizeof(val));

	set_instr(&proc->instruction, 3, 2, OCP2(T_REG, T_REG), ARG2(1, 2));
	st(vm, proc);

	test = loadreg(proc->registers + 2);
	if (test == val) {
		return (true);
	}
	return (false);
}

t_bool		test2(t_vm *vm, t_process *proc) {
	int		val = 30;

	storeg(proc->registers + 1, &val, sizeof(val));

	set_instr(&proc->instruction, 3, 2, OCP2(T_REG, T_REG), ARG2(400, 2));
	st(vm, proc);

	return (true);
}

t_bool		test5(t_vm *vm, t_process *proc) {
	int		val = 30;

	storeg(proc->registers + 1, &val, sizeof(val));

	set_instr(&proc->instruction, 3, 2, OCP2(T_REG, T_REG), ARG2(1, -1));
	st(vm, proc);

	return (true);
}

t_bool		test3(t_vm *vm, t_process *proc) {
	int		val = 30;
	int		pos = 12;
	int		real_pos = proc->pc + (pos % IDX_MOD);
	int		test;

	storeg(proc->registers + 1, &val, sizeof(val));

	set_instr(&proc->instruction, 3, 2, OCP2(T_REG, T_IND), ARG2(1, pos));
	st(vm, proc);

	test = loadmem(&vm->arena, sizeof(val), real_pos);
	if (test == val) {
		return (true);
	}
	return (false);
}

t_bool		test4(t_vm *vm, t_process *proc) {
	int		val = 30;
	int		pos = 40 + IDX_MOD;
	int		real_pos = proc->pc + (pos % IDX_MOD);
	int		test;

	storeg(proc->registers + 1, &val, sizeof(val));
	
	set_instr(&proc->instruction, 3, 2, OCP2(T_REG, T_IND), ARG2(1, pos));
	st(vm, proc);

	test = loadmem(&vm->arena, sizeof(val), real_pos);
	if (test == val) {
		return (true);
	}
	return (false);
}

void		st_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2,
		test3,
		test4,
		test5
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "STore");
}
