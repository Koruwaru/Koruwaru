#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {
	int		_1 = 13;
	int		_2 = 17;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	add(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _1 + _2 && proc->carry == (_1 + _2 == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {
	int		_1 = -13;
	int		_2 = 17;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	add(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _1 + _2 && proc->carry == (_1 + _2 == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test3(t_vm *vm, t_process *proc) {
	int		_1 = -10;
	int		_2 = 10;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	add(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _1 + _2 && proc->carry == (_1 + _2 == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test4(t_vm *vm, t_process *proc) {
	int		_1 = 1312312300;
	int		_2 = 2000000000;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	add(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == _1 + _2 && proc->carry == (_1 + _2 == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test5(t_vm *vm, t_process *proc) {
	int		_1 = 1;
	int		_2 = 2;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(500, -1, 3));
	add(vm, proc);

	test = loadreg(proc->registers + 3);
	if (loadreg(proc->registers + 3) != 0) {
		return (false);
	}
	return (true);
}

void		add_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2,
		test3,
		test4,
		test5
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "ADD");
}
