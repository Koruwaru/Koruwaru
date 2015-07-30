/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storeg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 14:02:56 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 14:26:34 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

void		storeg(t_register *reg, void const *data, size_t size, size_t pc)
{
	pc = (pc + size - 1) % MEM_SIZE;
	ft_bzero(reg->data, REG_SIZE);
	while (size)
	{
		reg->data[size - 1] = ((char *)data)[pc];
		size--;
		pc = ((pc - 1) + MEM_SIZE) % MEM_SIZE;
	}
}
