/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 23:16:07 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:18:53 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_create(char *str)
{
	int		i;
	int		fd;

	i = 0;
	while (str[i] != 0)
		i++;
	str[i - 2] = 0;
	str = ft_strjoin(str, ".cor");
	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	return (fd);
}

int		error_arg(void)
{
	ft_putendl("Arg error");
	return (-1);
}
