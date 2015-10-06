/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 20:07:28 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 20:11:15 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int		count_all_tab(char **tab)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (tab[i])
	{
		while (tab[i][i2])
			i2++;
		i++;
	}
	return (i2 + i);
}

char	*colle_tab(char **tab)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (tab[i])
	{
		ret = ft_strjoin(ret, tab[i]);
		i++;
	}
	return (ret);
}

char	*ft_strndup(char *line, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (n && line[i])
	{
		str[i] = line[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}

void	str_digit(char *s, int c)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '+' && *s != '-')
			err_msg("Lexical error", c);
		s++;
	}
}
