#ifndef TEST_H
# define TEST_H

# include "vm_protos.h"

# define HEADER(X)	("\x1B[32m" X "\x1B[0m")
# define COM(X)		("\x1B[34m" X "\x1B[0m")

# define ARGS(A, B, C) (t_uint []){A, B, C}

void	set_instr(t_instruction *instr, t_uint nb, t_arg_type ocp,
				  t_uint params[MAX_ARGS_NUMBER]);

void	live_tests(t_vm *vm, t_process *proc);
void	ld_tests(t_vm *vm, t_process *proc);
void	st_tests(t_vm *vm, t_process *proc);
void	add_tests(t_vm *vm, t_process *proc);
void	sub_tests(t_vm *vm, t_process *proc);
void	and_tests(t_vm *vm, t_process *proc);
void	or_tests(t_vm *vm, t_process *proc);
void	xor_tests(t_vm *vm, t_process *proc);

#endif

