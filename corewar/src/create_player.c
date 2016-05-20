/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:59:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/27 19:02:45 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "vm_protos.h"
#include "libft.h"

static size_t	ft_strlen_limit(char const *str, size_t limit)
{
	size_t	i;

	i = 0;
	while (*str && i < limit)
	{
		str++;
		i++;
	}
	return (i);
}

t_player		*create_player(size_t id, char const *name)
{
	t_player	*tmp;
	size_t		size;
	char		*newname;

	tmp = (t_player *)malloc(sizeof(t_player));
	if (tmp == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	size = ft_strlen_limit(name, PROG_NAME_LENGTH);
	newname = ft_strnew(size);
	if (newname == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	ft_memcpy(newname, name, size);
	tmp->name = newname;
	tmp->id = id;
	return (tmp);
}
