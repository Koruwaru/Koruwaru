/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:58:55 by jyim              #+#    #+#             */
/*   Updated: 2015/09/29 20:08:19 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_name_comment(t_asm *assembleur)
{
	if (!assembleur->name)
		err_msg("Name missing", assembleur->line);
	else if (!assembleur->comment)
		err_msg("Comment missing", assembleur->line);
}

char	**init_parsering(int *i, int *bol, char *l)
{
	*i = 0;
	*bol = 0;
	return (ft_sp_strsplit(l));
}

void	parse_file(char *l, t_asm *assembleur)
{
	char	**tab;
	int		bol;
	int		i;
	char	*ret[2];

	tab = init_parsering(&i, &bol, l);
	if (count_tab(tab) < 1)
		return ;
	check_name_comment(assembleur);
	if (tab[i][ft_strlen(tab[i]) - 1] == LABEL_CHAR)
	{
		tab[i][ft_strlen(tab[i]) - 1] = 0;
		i++;
		bol = 1;
		assembleur->label = add_label(assembleur->label,\
				create_label(tab[0], assembleur->count), assembleur->line);
	}
	if (count_tab(tab) < 2 && bol == 1)
		return ;
	else if (count_tab(tab) < 2 && bol == 0)
		arg_missing(assembleur->line);
	ret[0] = tab[i];
	ret[1] = colle_tab(tab + (i + 1));
	assembleur->bytecode = add_bytecode(ret, assembleur->bytecode,\
			&(assembleur->count), assembleur->line);
}
