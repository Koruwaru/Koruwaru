/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:37:15 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 16:05:39 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PROTOS_H
# define VM_PROTOS_H

# include "vm_types.h"

void		init_vm(t_vm *vm, size_t nb_players, t_list const *players,
					t_list const *programs);

t_player	*create_player(size_t id, char const *name);

void		*get_program(char const *data, size_t data_s, size_t *size);

t_process	*create_process(size_t id, size_t pc, t_arena const *arena);
t_process	*dup_process(t_process const *src);

void		dump_data(void const *a, size_t size, size_t line_s);

t_op const	*get_op(char op_code);

void		load_instr(t_process *proc, t_arena const *arena, size_t pc);

void		storeg(t_register *reg, void const *data, size_t size, size_t pc);
void		ltob(void *data, size_t size);

void		*get_file_data(char const *name, size_t *size);
#endif