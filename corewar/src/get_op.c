/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 17:17:21 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/29 17:24:12 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include "libft.h" //virer

t_op const	*get_op(char op_code)
{
	int		i;
	char	tmp;

	i = 0;
	while ((tmp = g_op_tab[i].op_code) != 0)
	{
		if (tmp == op_code)
			return (g_op_tab + i);
		i++;
	}
	return (NULL);
}
