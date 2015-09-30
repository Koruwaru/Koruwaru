/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 18:11:24 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/30 14:56:10 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_TYPES_H
# define VM_TYPES_H

# include <stddef.h>
# include "op.h"
# include "list.h"

typedef enum	e_bool
{
	false = 0,
	true = 1

}				t_bool;

typedef struct	s_register
{
	char		data[REG_SIZE];

}				t_register;

typedef unsigned int	t_uint;

typedef struct	s_instruction
{
	char		opcode;
	t_uint		nb_params;
	t_arg_type	args_types[MAX_ARGS_NUMBER];
	int			params[MAX_ARGS_NUMBER];
	t_uint		size;

}				t_instruction;

typedef struct	s_process
{
	size_t			id;
	t_register		registers[REG_NUMBER + 1];
	size_t			pc;
	t_bool			carry;
	int				cycles_since_live;
	size_t			remaining_cycles;
	t_instruction	instruction;

}				t_process;

typedef struct	s_player
{
	char const	*name;
	int			id;

}				t_player;

typedef struct	s_arena
{
	char		mem[MEM_SIZE];

}				t_arena;

typedef struct	s_args_data
{
	int			dump_cycles;
	t_list		*players_data;
	int			players_nb;
	int			next_player;

}				t_args_data;

typedef struct	s_vm
{
	size_t			next_proc_id;
	size_t			nb_players;
	size_t			nb_lives;
	size_t			checks;
	size_t			actual_cycle;
	t_player		players[MAX_PLAYERS];
	t_player const	*last_living_player;
	t_list			*processes;
	int				cycles;
	int				cycles_to_die;
	t_arena			arena;
	int				dump_cycles;

}				t_vm;

typedef struct	s_player_data
{
	char const	*filename;
	int			id;

}				t_player_data;

typedef void	(*t_instrf)(t_vm *vm, t_process *process);

#endif
