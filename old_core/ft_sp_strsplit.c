/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_strsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:09:54 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:14:34 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static int			ft_is_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == ',')
		return (1);
	else if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

static size_t		count_w(char const *s)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_is_white(s[i]))
			i++;
		if (!ft_is_white(s[i]) && s[i])
		{
			j++;
			i++;
			while (!ft_is_white(s[i]) && s[i])
				i++;
		}
	}
	return (j);
}

static char			*add_w(size_t *i, char const *s)
{
	size_t				size;
	size_t				j;
	char				*word;

	size = *i;
	j = 0;
	while (s[size] && !ft_is_white(s[size]))
		size++;
	word = ft_strnew(size - *i);
	if (word)
	{
		while (*i < size)
		{
			word[j] = s[*i];
			j++;
			*i += 1;
		}
		return (word);
	}
	return (0);
}

char				**ft_sp_strsplit(char const *s)
{
	char				**tab;
	size_t				o;
	size_t				*i;
	size_t				j;

	o = 0;
	i = &o;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char **) malloc(sizeof(char *) * (count_w(s) + 1));
	if (tab)
	{
		while (j < count_w(s))
		{
			while (ft_is_white(s[*i]))
				*i += 1;
			if (!ft_is_white(s[*i]) && s[*i])
				tab[j++] = add_w(i, s);
		}
		tab[j] = 0;
		return (tab);
	}
	return (0);
}
