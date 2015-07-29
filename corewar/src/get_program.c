/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:50:26 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 16:51:20 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

void		*get_program(char const *data, size_t data_s, size_t *size)
{
	void		*program;
	header_t	*hdr;
	unsigned int	tmpsize;

	if (data_s < sizeof(header_t))
	{
		ft_putendl_fd("You call that a file ? xD", 2);
		return (NULL);
	}
	hdr = (header_t *)data;
	tmpsize = hdr->prog_size;
	ltob(&tmpsize, sizeof(tmpsize));
	*size = tmpsize;
	tmpsize = hdr->magic;
	ltob(&tmpsize, sizeof(tmpsize));
	if (tmpsize != COREWAR_EXEC_MAGIC || *size != data_s - sizeof(header_t))
	{
		ft_putendl_fd("Bad header", 2);
		return (NULL);
	}
	program = (void *)malloc(*size);
	if (program == NULL)
	{
		perror("Malloc error");
		return (NULL);
	}
	ft_memcpy(program, data + sizeof(header_t), *size);
	return (program);
}
