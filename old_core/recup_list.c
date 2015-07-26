/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:13:33 by jyim              #+#    #+#             */
/*   Updated: 2015/07/26 18:38:06 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

char		*ft_strndup(char *line, int n)
{
	char	*str;
	int		i = 0;

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

char		*suppr_comment(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '#')
			break ;
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = ' ';
	tmp[i + 1] = '\0';
	return (tmp);
}

t_lex		*lex_begin(char **tableau)
{
	int		i;
	t_lex	*tmp;

	tmp = NULL;
	i = 0;
	while (tableau[i])
	{
		tmp = end_l(tmp, tableau[i]);
		i++;
	}
	return (tmp);
}

void		aff_list(t_lex *l)
{
	if (l == NULL)
		return ;
	else
	{
		ft_putendl(l->s);
		aff_list(l->next);
	}
}

char		*ft_get_head(char *line)
{
	char	*str;

	while (*line && *line != '"')
		line++;
	line++;
	str = ft_strndup(line, ft_strlen(line) - 1);
	return (str);
}

t_lex		*recup_file(char **av, t_header *head)
{
	int		fd;
	char	*line;
	char	*final;
	char	**tableau;
	t_lex	*l;

	final = NULL;
	l = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (ft_strncmp(line, NAME_CMD_STR, ft_strlen(NAME_CMD_STR))
			&& ft_strncmp(line, COMMENT_CMD_STR, ft_strlen(COMMENT_CMD_STR)))
	 	{
			line = suppr_comment(line);
			if (final)
				final = ft_strjoin(final, line);
			else
				final = ft_strdup(line);
		}
		else if (!ft_strncmp(line, NAME_CMD_STR, ft_strlen(NAME_CMD_STR)))
			head->prog_name = ft_get_head(line);
		else if (!ft_strncmp(line, COMMENT_CMD_STR, ft_strlen(COMMENT_CMD_STR)))
			head->comment = ft_get_head(line);
		free(line);
	}
	tableau = ft_sp_strsplit(final);
	l = lex_begin(tableau);
	close(fd);
	return (l);
}
