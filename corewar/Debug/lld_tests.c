#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {
	int		_1 = 32;
	int		test;

	set_instr(&proc->instruction, 13, 2, OCP2(T_DIR, T_REG), ARG2(_1, 3));
	lld(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _1) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {
	int		_1 = 32;
	int		pc = 10;
	int		test;

	ltob(&_1, sizeof(_1));
	stomem(&vm->arena, &_1, sizeof(_1), pc);
	set_instr(&proc->instruction, 13, 2, OCP2(T_IND, T_REG), ARG2(pc, 3));
	lld(vm, proc);

	test = loadreg(proc->registers + 3);
	ltob(&test, sizeof(test));
	if (test == _1) {
		return (true);
	}
	return (false);
}

void		lld_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "Long LoaD");
}
