/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 20:12:31 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 20:14:37 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*remove_quote(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			line[i] = 0;
			break ;
		}
		i++;
	}
	return (line);
}

void	rspaces(char *source)
{
	char *i;
	char *j;

	i = source;
	j = source;
	while (*j != 0)
	{
		*i = *j++;
		if (*i != ' ' || *i == '\t')
			i++;
	}
	*i = 0;
}

char	*lets_read(int fd)
{
	char str[2];
	char *ret;

	ret = ft_strdup("");
	while (read(fd, str, 1))
	{
		str[1] = 0;
		if (str[0] == '"')
			return (ret);
		ret = ft_strjoin(ret, str);
	}
	return (NULL);
}

char	*give_name(char *s, t_asm a, int fd)
{
	char *str;

	str = NULL;
	if (!a.name)
		str = ft_get_head(s, fd);
	else
		err_msg("Name already present", a.line);
	if (ft_strlen(str) > 128)
		err_msg("Name is too long. (128 max)", a.line);
	return (str);
}

char	*give_comment(char *s, t_asm a, int fd)
{
	char *str;

	str = NULL;
	if (!a.comment)
		str = ft_get_head(s, fd);
	else
		err_msg("Comment already present", a.line);
	if (ft_strlen(str) > 2048)
		err_msg("Comment is too long. (2048 max)", a.line);
	return (str);
}
