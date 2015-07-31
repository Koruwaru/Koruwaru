/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:54:46 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:55:14 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int open_asm(int ac, char **av)
{
	int fd;

	if (ac < 2 || ac > 2)
		bad_argument();
	if ((fd = open_file(av[1])) == -1)
		open_fail();
	return (fd);
}

int main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**tab;
	t_asm	assembleur;

	fd = open_asm(ac, av);
	init_asm(&assembleur);
	while (get_next_line(fd, &line))
	{
		assembleur.line += 1;
		line = suppr_comment(line);
		if (line && line[0] != '.' && line[0] != COMMENT_CHAR)
		{
			tab = ft_strsplit(line, ';');
			parse_file(tab[0], &assembleur);
		}
		else if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			assembleur.name = give_name(line, assembleur, fd);
		else if (!ft_strncmp(line, COMMENT_CMD_STRING,\
					ft_strlen(COMMENT_CMD_STRING)))
			assembleur.comment = give_comment(line, assembleur, fd);
	}
	fill_label(&assembleur);
	put_to_file(av[1], assembleur.bytecode, assembleur);
	return (0);
}
