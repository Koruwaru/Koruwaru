/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:47:16 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 18:39:33 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

int			count_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char		**cpy_tab(char **tab)
{
	char		**tmp;
	int			i;

	tmp = (char **)malloc(sizeof(char *) * (count_tab(tab) + 1));
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

t_lex		*end_l(t_lex *l, char *string)
{
	t_lex	*tmp;
	t_lex	*tmp2;

	tmp = l;
	tmp2 = (t_lex *)malloc(sizeof(t_lex));
	tmp2->s = ft_strdup(string);
	tmp2->next = NULL;
	tmp2->prev = NULL;
	if (l == NULL)
		return (tmp2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	return (l);
}

t_pars		*end_l_pars(t_pars *l, char **tab, char *string, int i)
{
	t_pars	*tmp;
	t_pars	*tmp2;

	tmp = l;
	tmp2 = (t_pars *)malloc(sizeof(t_pars));
	tmp2->islab = i;
	tmp2->label = string ? ft_strdup(string) : NULL;
	tmp2->cmd = cpy_tab(tab);
	tmp2->next = NULL;
	tmp2->prev = NULL;
	if (l == NULL)
		return (tmp2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	return (l);
}

t_pars		*pars_lab(t_pars *l, char *string)
{
	t_pars		*tmp;

	tmp = l;
	while (tmp->next)
		tmp = tmp->next;
	tmp->label = ft_strdup(string);
	tmp->islab = 1;
	return (l);
}
