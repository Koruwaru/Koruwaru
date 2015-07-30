/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:59:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 14:37:53 by tmielcza         ###   ########.fr       */
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

	tmp = (t_player *)malloc(sizeof(t_player));
	ft_memcpy((char *)tmp->name, name, ft_strlen_limit(name, PROG_NAME_LENGTH));
	if (tmp->name == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	tmp->id = id;
	return (tmp);
}
