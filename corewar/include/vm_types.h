/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 18:11:24 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/27 18:49:44 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_TYPES_H
# define VM_TYPES_H

# include <stddef.h>
# include "op.h"
# include "list.h"

// http://www.cs.utexas.edu/users/djimenez/utsa/cs3343/lecture20.html
typedef enum	e_bool
{
	true = 0,
	false

}				t_bool;

typedef struct	s_register
{
	char		data[REG_SIZE];

}				t_register;

typedef struct	s_instruction
{
	char		opcode;
	size_t		nb_params;
	t_arg_type	params_types[MAX_ARGS_NUMBER];
	size_t		params[MAX_ARGS_NUMBER];

}				t_instruction;

typedef struct	s_process
{
	t_register		registers[REG_NUMBER];
	size_t			pc;
	t_bool			carry;
	size_t			nb_lives;
	size_t			remaining_cycles;
	t_instruction	instruction;

}				t_process;

typedef struct	s_player
{
	char const	*name;
	size_t		id;

}				t_player;

typedef struct	s_arena
{
	char		mem[MEM_SIZE];

}				t_arena;

typedef struct	s_vm
{
	size_t			nb_players;
	t_player		players[MAX_PLAYERS];
	t_player const	*last_living_player;
	t_list			*processes;
	t_arena			arena;

}				t_vm;

#endif
