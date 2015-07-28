/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:22:25 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 16:23:17 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "vm_protos.h"

t_process	*dup_process(t_process const *src)
{
	t_process	*proc;

	proc = (t_process *)malloc(sizeof(t_process));
	if (proc == NULL)
	{
		perror("Malloc error");
		return (NULL);
	}
	ft_memcpy(proc->registers, src->registers, sizeof(src->registers));
	proc->pc = src->pc;
	proc->carry = src->carry;
	proc->nb_lives = proc->nb_lives;
	proc->remaining_cycles = src->remaining_cycles;
	proc->instruction = src->instruction;
	return (proc);
}
