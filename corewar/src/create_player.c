/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:46:16 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/27 18:50:03 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm_protos.h"

t_player	*create_player(size_t id, char const *name)
{
	t_player	*tmp;

	tmp = (t_player *)malloc(sizeof(t_player));
	tmp->name = name;
	tmp->id = id;
	return (tmp);
}
