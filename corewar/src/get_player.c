/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 11:08:24 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 11:21:34 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

t_player const	*get_player(t_vm const *vm, size_t id)
{
	size_t		i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->players[i].id == id)
		{
			return vm->players + i;
		}
	}
	return (NULL);
}
