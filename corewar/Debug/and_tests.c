#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {
	int		_1 = 17;
	int		_2 = 17;
	int		res = _1 & _2;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	and_(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == res && proc->carry == (res == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {
	int		_1 = 17;
	int		_2 = 17;
	int		res = _1 & _2;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_DIR, T_REG), ARG3(1, _2, 3));
	and_(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == res && proc->carry == (res == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test3(t_vm *vm, t_process *proc) {
	int		_1 = 17;
	int		_2 = 17;
	int		_11 = _1;
	int		res = _1 & _2;
	int		pos = 10;
	int		test;

	ltob(&_11, sizeof(_11));
	stomem(&vm->arena, &_11, sizeof(_11), pos);

	set_instr(&proc->instruction, 3, 2, OCP3(T_IND, T_DIR, T_REG), ARG3(pos, _2, 3));
	and_(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == res && proc->carry == (res == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test4(t_vm *vm, t_process *proc) {
	int		_1 = 0xF0;
	int		_2 = 0x0F;
	int		res = _1 & _2;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1, 2, 3));
	and_(vm, proc);

	test = loadreg(proc->registers + 3);
	if (test == res && proc->carry == (res == 0)) {
		return (true);
	}
	return (false);
}

static t_bool		test5(t_vm *vm, t_process *proc) {
	int		_1 = 0xF0;
	int		_2 = 0x0F;
//	int		res = _1 & _2;
	int		test;

	storeg(proc->registers + 1, &_1, sizeof(_1));
	storeg(proc->registers + 2, &_2, sizeof(_2));

	set_instr(&proc->instruction, 3, 2, OCP3(T_REG, T_REG, T_REG), ARG3(1123, 222, 3));
	and_(vm, proc);

	test = loadreg(proc->registers + 3);
	if (loadreg(proc->registers + 3) != 0) {
		return (false);
	}
	return (true);
}

void		and_tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2,
		test3,
		test4,
		test5
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "AND");
}
