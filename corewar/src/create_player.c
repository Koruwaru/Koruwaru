/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 16:59:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 16:59:25 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "vm_protos.h"
#include "libft.h"

t_player	*create_player(size_t id, char const *name)
{
	t_player	*tmp;

	tmp = (t_player *)malloc(sizeof(t_player));
	tmp->name = ft_strdup(name);
	if (tmp->name == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	tmp->id = id;
	return (tmp);
}
