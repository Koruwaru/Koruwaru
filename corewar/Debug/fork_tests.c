#include <stdio.h>

#include "vm_protos.h"
#include "test.h"
#include "libft.h"

static t_bool		test1(t_vm *vm, t_process *proc) {

	size_t		len_before;
	size_t		len_after;

	len_before = ft_lstlen(vm->processes);
	set_instr(&proc->instruction, 12, 1, OCP1(T_DIR), ARG1(10));
	fork_(vm, proc);

	len_after = ft_lstlen(vm->processes);
	if (len_after == len_before + 1) {
		return (true);
	}
	return (false);
}

static t_bool		test2(t_vm *vm, t_process *proc) {

	int			move = 10;
	int			comp = 0;
	t_process	*proc_cpy;
	
	set_instr(&proc->instruction, 12, 1, OCP1(T_DIR), ARG1(move));
	fork_(vm, proc);

	proc_cpy = vm->processes->content;

	comp = !ft_memcmp(proc_cpy->registers, proc->registers, sizeof(proc->registers));
	comp = !(proc_cpy->pc == (proc->pc + (move % IDX_MOD)));
	if (comp != 0) {
		return (true);
	}
	return (false);
}

void		fork__tests(t_vm *vm, t_process *proc)
{
	static test_func funcs[] = {
		test1,
		test2
	};

	unit_tests(funcs, vm, proc, sizeof(funcs) / sizeof(funcs[0]), "FORK");
}
