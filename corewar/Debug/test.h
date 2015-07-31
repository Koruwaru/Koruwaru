#ifndef TEST_H
# define TEST_H

# include "vm_protos.h"

# define HEADER(X)	("\x1B[32m" X "\x1B[0m")
# define COM(X)		("\x1B[34m" X "\x1B[0m")
# define ERR(X)		("\x1B[31m" X "\x1B[0m")

# define ARGS(A, B, C) (t_uint []){A, B, C}
# define ARG1(A) ARGS(A, 0, 0)
# define ARG2(A, B) ARGS(A, B, 0)
# define ARG3(A, B, C) ARGS(A, B, C)

# define OCP(A, B, C) (t_arg_type []){A, B, C}
# define OCP1(A) OCP(A, 0, 0)
# define OCP2(A, B) OCP(A, B, 0)
# define NOPE OCP(0, 0, 0)

void	set_instr(t_instruction *instr, t_uint opcode, t_uint nb,
				  t_arg_type ocp[MAX_ARGS_NUMBER],
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
