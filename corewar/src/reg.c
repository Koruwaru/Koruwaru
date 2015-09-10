/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:31:38 by crenault          #+#    #+#             */
/*   Updated: 2015/09/10 20:02:04 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

void		storeg(t_register *reg, void const *data, size_t size)
{
	char const	*tmp_data;
	char		*tmp_reg;
	char		*end_reg;

	tmp_reg = reg->data;
	end_reg = tmp_reg + (size < REG_SIZE ? size : REG_SIZE);
	tmp_data = (char const *)data;
	ft_bzero(reg->data, REG_SIZE);
	while (tmp_reg != end_reg)
	{
		*tmp_reg = *tmp_data;
		tmp_reg++;
		tmp_data++;
	}
}

int			loadreg(t_register const *reg)
{
	return (*(int *)(void *)reg->data);
}
