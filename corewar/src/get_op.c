/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 17:17:21 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/28 18:58:07 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op const	*get_op(char op_code)
{
	int		i;
	char	opcode;

	i = 0;
	while ((opcode = g_op_tab[i].op_code) != 0)
	{
		if (opcode == op_code)
			return (g_op_tab + i);
		i++;
	}
	return (NULL);
}
