#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {
	int		_1 = 2;
	int		_2 = 1;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));
	ltob(&_3, sizeof(_3));
	stomem(&vm->arena, &_3, sizeof(_3), pc);
	ltob(&_3, sizeof(_3));

	set_instr(&proc->instruction, 10, 3, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	lldi(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {
	int		_1 = 12;
	int		_2 = 1;
	int		_2p = 4;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	ltob(&_2, sizeof(_2));
	stomem(&vm->arena, &_2, sizeof(_2), _2p);
	ltob(&_3, sizeof(_3));
	stomem(&vm->arena, &_3, sizeof(_3), pc);
	ltob(&_3, sizeof(_3));

	set_instr(&proc->instruction, 10, 3, OCP3(T_REG, T_IND, T_REG), ARG3(1, _2p, 3));
	lldi(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test3(t_vm *vm, t_process *proc) {
	int		_1 = 2;
	int		_2 = 1;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	ltob(&_3, sizeof(_3));
	stomem(&vm->arena, &_3, sizeof(_3), pc);
	ltob(&_3, sizeof(_3));

	set_instr(&proc->instruction, 10, 3, OCP3(T_DIR, T_DIR, T_REG), ARG3(_1, _2, 3));
	lldi(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test4(t_vm *vm, t_process *proc) {
	int		_1 = 12;
	int		_2 = 11;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	stomem(&vm->arena, &_3, sizeof(_3), pc);

	set_instr(&proc->instruction, 10, 3, OCP3(T_DIR, T_DIR, T_REG), ARG3(_1, _2, 3));
	lldi(vm, proc);

	test = loadreg(proc->registers + 3);
	ltob(&test, sizeof(test));
	if (test == _3) {
		return (true);
	}
	return (false);
}

static t_bool		test5(t_vm *vm, t_process *proc) {
	int		_1 = 12;
	int		_2 = 11;
	int		pc = _1 + _2;
	int		_3 = 42;
	int		test;

	ltob(&_3, sizeof(_3));
	stomem(&vm->arena, &_3, sizeof(_3), pc);
	ltob(&_3, sizeof(_3));

	set_instr(&proc->instruction, 10, 3, OCP3(T_IND, T_IND, T_IND), ARG3(_1, _2, 3));
	lldi(vm, proc);

	test = loadreg(proc->registers + 3);
	return (true);
}

void		lldi_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2,
		test3,
		test4,
		test5
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "Long LoaD Indirect");
}
