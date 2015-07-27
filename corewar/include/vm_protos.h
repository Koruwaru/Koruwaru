/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_protos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 15:37:15 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/27 16:34:59 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PROTOS_H
# define VM_PROTOS_H

# include <stdio.h>
# include "vm_types.h"

void		init_vm(t_vm *vm, size_t nb_players, t_list const *players,
					t_list const *programs);

t_player	*create_player(size_t id, char const *name);

void		*get_program(int fd, size_t *size);

t_process	*create_process(t_register const *regs, size_t pc, t_bool carry);

void		init_instruction(t_instruction *instr, t_arena const *a, size_t pc);

#endif
