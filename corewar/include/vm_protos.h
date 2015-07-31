/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:11:27 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:11:27 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PROTOS_H
# define VM_PROTOS_H

# include "vm_types.h"

void		init_vm(t_vm *vm, size_t nb_players, t_list const *players,
					t_list const *programs);

t_player	*create_player(size_t id, char const *name);

void		*get_program(char const *data, size_t data_s, size_t *size);

t_process	*create_process(size_t id, size_t pc);
t_process	*dup_process(t_process const *src);

void		dump_data(void const *a, size_t size, size_t line_s);

t_arg_type	get_param_type(char ocp, size_t param_id);

t_op const	*get_op(char op_code);

t_bool		check_param(t_arg_type type, t_uint value);
int			get_value(t_arg_type type, t_uint value, t_arena const *a,
						t_register const *regs);

void		load_instr(t_process *proc, t_arena const *arena);

void		storeg(t_register *reg, void const *data, size_t data_s, size_t pc);
int			loadreg(t_register const *reg);

void		stomem(t_arena *a, void const *data, size_t data_s, size_t pc);
int			loadmem(t_arena const *a, size_t size, size_t pc);

void		ltob(void *data, size_t size);

void		*get_file_data(char const *name, size_t *size);

void		set_pc(size_t *pc, size_t new_pc);
void		move_pc(size_t *pc, int steps);

void		null(t_vm *vm, t_process *process);
void		live(t_vm *vm, t_process *process);
void		ld(t_vm *vm, t_process *process);
void		st(t_vm *vm, t_process *process);
void		add(t_vm *vm, t_process *process);
void		sub(t_vm *vm, t_process *process);
void		and_(t_vm *vm, t_process *process);
void		or_(t_vm *vm, t_process *process);
void		xor_(t_vm *vm, t_process *process);

void		zjmp(t_vm *vm, t_process *process);
void		ldi(t_vm *vm, t_process *process);
void		sti(t_vm *vm, t_process *process);
void		fork_(t_vm *vm, t_process *process);
void		lld(t_vm *vm, t_process *process);
void		lldi(t_vm *vm, t_process *process);
void		lfork(t_vm *vm, t_process *process);
void		aff(t_vm *vm, t_process *process);

#endif
