/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 20:15:15 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 20:16:18 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*erase_char(char *s)
{
	while (*s && (*s == ':' || *s == '%'))
		s++;
	return (s);
}

void	init_get_head(int *i, int *flag)
{
	*i = 0;
	*flag = 0;
}

char	*ft_get_head(char *line, int fd)
{
	char	*str;
	int		i;
	int		flag;

	init_get_head(&i, &flag);
	while (*line && *line != '"')
		line++;
	line++;
	while (line[i])
	{
		if (line[i] == '"')
		{
			line[i] = 0;
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
	{
		line = ft_strjoin(line, lets_read(fd));
		line = remove_quote(line);
	}
	str = ft_strndup(line, ft_strlen(line));
	return (str);
}
