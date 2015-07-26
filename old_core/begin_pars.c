/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 18:00:27 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:12:26 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

char		**add_tab(char **tab, char *string)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (count_tab(tab) + 2));
	i = 0;
	if (tab == NULL)
	{
		tmp[0] = ft_strdup(string);
		tmp[1] = NULL;
		return (tmp);
	}
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = ft_strdup(string);
	tmp[i + 1] = NULL;
	return (tmp);
}

char		**free_tab(char **tmp2)
{
	int		i;

	i = 0;
	if (tmp2 == NULL)
		return (NULL);
	while (tmp2[i])
	{
		free(tmp2[i]);
		i++;
	}
	tmp2 = NULL;
	return (tmp2);
}

t_pars		*fill_pars(t_lex *l, t_pars *l2, char **tab)
{
	t_lex	*tmp;
	char	**tmp2;

	tmp = l;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp2)
		{
			l2 = end_l_pars(l2, tmp2, NULL, 0);
			tmp2 = free_tab(tmp2);
		}
		if (tmp->prev && is_label(tmp->prev->s) == 1)
			l2 = pars_lab(l2, tmp->prev->s);
		if (in_tab(tmp->s, tab) == 1)
		{
			tmp2 = add_tab(tmp2, tmp->s);
			while (tmp->next && in_tab(tmp->next->s, tab) == 0 &&
					is_label(tmp->next->s) == 0)
			{
				tmp2 = add_tab(tmp2, tmp->next->s);
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	if (tmp2)
	{
		l2 = end_l_pars(l2, tmp2, NULL, 0);
		tmp2 = free_tab(tmp2);
	}
	return (l2);
}

t_pars		*pars_begin(t_lex *l, char **tableau)
{
	t_pars	*tmp;

	tmp = NULL;
	tmp = fill_pars(l, tmp, tableau);
	return (tmp);
}
