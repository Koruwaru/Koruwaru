#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {
	int		_1 = 1;
	int		_2 = 2;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));
	storeg(proc->registers + 3, &_3, sizeof(_3));
	set_instr(&proc->instruction, 11, 3, OCP3(T_REG, T_REG, T_REG), ARG3(3, 1, 2));
	sti(vm, proc);

	test = loadmem(&vm->arena, sizeof(test), pc);
	ltob(&test, sizeof(test));
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {
	int		_1 = 1;
	int		_2 = 30;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 3, &_3, sizeof(_3));
	set_instr(&proc->instruction, 11, 3, OCP3(T_REG, T_REG, T_DIR), ARG3(3, 1, _2));
	sti(vm, proc);

	test = loadmem(&vm->arena, sizeof(test), pc % IDX_MOD);
	ltob(&test, sizeof(test));
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test3(t_vm *vm, t_process *proc) {
	int		_1 = 1;
	int		_1_mem = 6;
	int		_2 = 30;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	ltob(&_1, sizeof(_1));	
	stomem(&vm->arena, &_1, sizeof(_1), _1_mem);
	storeg(proc->registers + 3, &_3, sizeof(_3));
	set_instr(&proc->instruction, 11, 3, OCP3(T_REG, T_IND, T_DIR), ARG3(3, _1_mem, _2));
	sti(vm, proc);

	test = loadmem(&vm->arena, sizeof(test), pc % IDX_MOD);
	ltob(&test, sizeof(test));
	if (test == _3) {
		return (true);
	}
	return (false);
}

void		sti_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2,
		test3
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "STore Indirect");
}
