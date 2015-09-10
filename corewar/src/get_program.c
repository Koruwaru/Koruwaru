/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:50:26 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:58:34 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

void		*get_program(void const *data, size_t data_s, size_t *size)
{
	void			*program;
	unsigned int	tmpsize;

	if (data_s < sizeof(t_header))
	{
		ft_putendl_fd("You call that a file ? xD", 2);
		return (NULL);
	}
	tmpsize = ((t_header *)data)->prog_size;
	ltob(&tmpsize, sizeof(tmpsize));
	*size = tmpsize;
	tmpsize = ((t_header *)data)->magic;
	ltob(&tmpsize, sizeof(tmpsize));
	if (tmpsize != COREWAR_EXEC_MAGIC || *size != data_s - sizeof(t_header))
	{
		ft_putendl_fd("Bad header", 2);
		return (NULL);
	}
	if ((program = (void *)malloc(*size)) == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	ft_memcpy(program, (char const *)data + sizeof(t_header), *size);
	return (program);
}
