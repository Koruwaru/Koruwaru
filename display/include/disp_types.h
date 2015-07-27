/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 23:16:12 by crenault          #+#    #+#             */
/*   Updated: 2015/07/27 23:55:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISP_TYPES_H
# define DISP_TYPES_H

typedef enum	e_bool
{
	true = 0,
	false

}				t_bool;

typedef struct	s_cell
{
	char		data;
	t_bool		pc;

}				t_cell;

typedef struct	s_arena
{
	t_cell		*mem;

}				t_arena;

#endif
