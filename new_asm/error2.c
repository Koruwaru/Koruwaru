/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:49:07 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:49:09 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void error_parse(int l)
{
	err_msg("Error while parsing", l);
}

void bad_parameter(int l)
{
	err_msg("Bad parameter", l);
}

void bad_parameter_nb(int l)
{
	err_msg("Bad parameter number", l);
}
