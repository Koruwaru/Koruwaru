/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:50:26 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/27 19:07:29 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

static void	*print_error_null(char const *str)
{
	ft_putstr_fd(str, 2);
	return (NULL);
}

void		*get_program(void const *data, size_t data_s, size_t *size)
{
	void			*program;
	unsigned int	tmpsize;

	if (data_s < sizeof(t_header))
		return (print_error_null("You call that a file ? xD"));
	tmpsize = ((t_header const *)data)->prog_size;
	ltob(&tmpsize, sizeof(tmpsize));
	*size = tmpsize;
	tmpsize = ((t_header const *)data)->magic;
	ltob(&tmpsize, sizeof(tmpsize));
	if (tmpsize != COREWAR_EXEC_MAGIC)
		return (print_error_null("Bad header/size"));
	if (*size != data_s - sizeof(t_header))
		return (print_error_null("Bad champion size in header."));
	if (*size > CHAMP_MAX_SIZE)
		return (print_error_null("BBW Champion..."));
	if ((program = (void *)malloc(*size)) == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	ft_memcpy(program, (char const *)data + sizeof(t_header), *size);
	return (program);
}
