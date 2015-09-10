/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 15:20:22 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/10 19:54:39 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "vm_protos.h"

void		ltob(void *data, size_t size)
{
	char	tmp;
	int		i;
	char	*tmpptr;

	tmpptr = data;
	i = (size - 2) / 2;
	while (i >= 0)
	{
		tmp = tmpptr[size - 1 - i];
		tmpptr[size - 1 - i] = tmpptr[i];
		tmpptr[i] = tmp;
		i--;
	}
}
