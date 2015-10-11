/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:48:35 by jyim              #+#    #+#             */
/*   Updated: 2015/10/11 20:09:30 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	bad_argument(void)
{
	ft_putendl_fd("Not enough | Too much argument/s", 2);
	exit(0);
}

void	open_fail(void)
{
	ft_putendl_fd("Error while trying to open asm file", 2);
	exit(0);
}

void	no_arg(int l)
{
	err_msg("No arg", l);
}

void	bad_instruction(int l)
{
	err_msg("Bad instruction", l);
}

void	arg_missing(int l)
{
	err_msg("Instruction without args", l);
}
