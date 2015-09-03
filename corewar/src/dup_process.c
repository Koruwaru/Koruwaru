/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:22:25 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/03 16:49:38 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "vm_protos.h"

t_process	*dup_process(t_process const *src)
{
	t_process	*new;

	new = (t_process *)malloc(sizeof(t_process));
	if (new == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	ft_memcpy(new->registers, src->registers, sizeof(src->registers));
	new->pc = src->pc;
	new->carry = src->carry;
	new->nb_lives = src->nb_lives;
	new->remaining_cycles = src->remaining_cycles;
	new->instruction = src->instruction;
	return (new);
}
