/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:47:50 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/06 18:01:21 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "vm_protos.h"

t_process	*create_process(size_t id, size_t pc)
{
	t_process	*proc;

	proc = (t_process *)malloc(sizeof(t_process));
	if (proc == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	ft_bzero(proc->registers, sizeof(proc->registers));
	storeg(&proc->registers[1], &id, sizeof(id));
	proc->id = 0;
	proc->pc = pc;
	proc->carry = 0;
	proc->cycles_since_live = 0;
	proc->remaining_cycles = 0;
	return (proc);
}
