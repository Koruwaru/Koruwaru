/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:50:26 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/27 20:21:30 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "vm_protos.h"
#include "libft.h"

t_bool		fill_program_infos(void *data, size_t fsize, size_t *size,
							   t_player *player)
{
	header_t	*hdr;

	hdr = (header_t *)data;
	*size = hdr->prog_size;
	if (hdr->magic != COREWAR_EXEC_MAGIC || *size != fsize - sizeof(header_t))
	{
		ft_putendl_fd("Bad header", 2);
		return (false);
	}
	// Fuck it
	return (true);
}

void		*get_program(int fd, size_t *size, t_player *player)
{
	char		*buff;
	size_t		fsize;
	size_t		pos;
	int			read_ret;
	void		*program;

	pos = 0;
	fsize = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (fsize < sizeof(header_t))
	{
		ft_putendl_fd("You call that a file ? xD", 2);
		return (NULL);
	}
	buff = (char *)malloc(fsize);
	if (buff == NULL)
	{
		perror("Malloc error");
		return (NULL);
	}
	while (pos != fsize)
	{
		read_ret = read(fd, buff + pos, fsize);
		if (read_ret < 0)
		{
			free(buff);
			perror("Naughty file");
			return (NULL);
		}
	}
	program = (void *)malloc(*size);
	if (program == NULL)
	{
		free(buff);
		perror("Malloc error");
		return (NULL);
	}
	ft_memcpy(program, buff + sizeof(header_t), *size);
	free(buff);
	return (program);
}
