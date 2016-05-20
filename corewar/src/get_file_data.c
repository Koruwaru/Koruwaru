/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:37:28 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:47:00 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vm_protos.h"

void		*get_file_data(char const *name, size_t *size)
{
	char	*buff;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror("Bad file");
		exit(1);
	}
	*size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buff = (char *)malloc(*size);
	if (buff == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	if (read(fd, buff, *size) < 0)
	{
		free(buff);
		perror("Naughty file");
		exit(1);
	}
	close(fd);
	return (buff);
}
