/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:52:06 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:53:40 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_inst		*create_inst(char *s, int where, t_inst *head, int c)
{
	t_inst *maillon;

	maillon = (t_inst *)malloc(sizeof(t_inst));
	maillon->is_label = 0;
	maillon->where = -1;
	maillon->s = ft_strdup(erase_char(s));
	maillon->opcode = 0;
	if (!head)
	{
		maillon->value = find_opcode(s);
		maillon->size = 1;
		if (maillon->value == -1)
			bad_instruction(c);
		maillon->opcode = is_op(maillon->value);
	}
	else
		find_value(s, maillon, head, c);
	maillon->where = where;
	maillon->next = NULL;
	return (maillon);
}

t_inst		*add_inst(t_inst *head, t_inst *maillon)
{
	t_inst *tmp;

	if (!head)
		return (maillon);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = maillon;
	return (head);
}

int			count_inst(t_inst *h)
{
	t_inst		*tmp;
	int			i;

	i = 0;
	tmp = h;
	if (!h)
		return (0);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
