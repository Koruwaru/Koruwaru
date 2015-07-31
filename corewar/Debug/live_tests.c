#include "vm_protos.h"
#include "test.h"

void		live_tests(t_vm *vm, t_process *proc)
{
	set_instr(&proc->instruction, 1, 0, ARGS(1, 0, 0));
}
