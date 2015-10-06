/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:49:30 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:50:51 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*create_label(char *s, int place)
{
	t_label *label;

	label = (t_label *)malloc(sizeof(t_label));
	label->name = ft_strdup(s);
	if (place)
		label->place = place;
	label->next = NULL;
	return (label);
}

void		check_label(t_label *h, t_label *m, int c)
{
	t_label *tmp;

	tmp = h;
	while (tmp)
	{
		if (!ft_strcmp(h->name, m->name))
			err_msg("Redefinition of label", c);
		tmp = tmp->next;
	}
}

t_label		*add_label(t_label *head, t_label *maillon, int c)
{
	t_label *tmp;

	if (!head)
		return (maillon);
	tmp = head;
	check_label(head, maillon, c);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = maillon;
	return (head);
}

void		while_label(t_label *tmp2, t_bytecode *tmp, t_inst *inst)
{
	while (tmp2)
	{
		if (!ft_strcmp(tmp2->name, inst->s))
		{
			if (tmp2->place < tmp->inst->where)
				inst->value = (tmp2->place - tmp->inst->where);
			else
				inst->value = (tmp2->place - tmp->inst->where);
			break ;
		}
		tmp2 = tmp2->next;
	}
}

void		fill_label(t_asm *assembleur)
{
	t_bytecode		*tmp;
	t_label			*tmp2;
	t_inst			*inst;

	tmp = assembleur->bytecode;
	while (tmp)
	{
		inst = tmp->inst;
		while (inst)
		{
			if (inst->is_label == 1)
			{
				tmp2 = assembleur->label;
				while_label(tmp2, tmp, inst);
			}
			inst = inst->next;
		}
		tmp = tmp->next;
	}
}
