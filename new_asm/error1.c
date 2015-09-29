/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:48:35 by jyim              #+#    #+#             */
/*   Updated: 2015/09/29 20:07:25 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	bad_argument(void)
{
	ft_putendl("Not enough | Too much argument/s");
	exit(0);
}

void	open_fail(void)
{
	ft_putendl("Error while trying to open asm file");
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
