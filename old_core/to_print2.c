/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 23:26:38 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:30:49 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		to_print2(int fd, int param, int i, char **tab)
{
	param = ft_atoi(tab[i] + 1);
	put_unsigned_char_fd(fd, param >> 24);
	put_unsigned_char_fd(fd, param >> 16);
	put_unsigned_char_fd(fd, param >> 8);
	put_unsigned_char_fd(fd, param);
}

void		to_print3(int fd, int param, int i, char **tab)
{
	param = ft_atoi(tab[i]);
	put_unsigned_char_fd(fd, param >> 8);
	put_unsigned_char_fd(fd, param);
}
