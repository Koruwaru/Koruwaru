/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:47:50 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 16:25:21 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "vm_protos.h"

t_process	*create_process(size_t id, size_t pc, t_arena const *arena)
{
	t_process	*proc;

	proc = (t_process *)malloc(sizeof(t_process));
	if (proc == NULL)
	{
		perror("Malloc error");
		return (NULL);
	}
	ft_bzero(proc->registers, sizeof(proc->registers));
	storeg(&proc->registers[0], &id);
	proc->pc = pc;
	proc->carry = 0;
	proc->nb_lives = 0;
	proc->remaining_cycles = 0;
	init_instr(&proc->instruction, arena, pc);
	return (proc);
}
