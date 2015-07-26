/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:51:27 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:22:44 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

char	**fill_tab(void)
{
	char	**tableau;

	tableau = (char **)malloc(sizeof(char *) * 17);
	tableau[0] = ft_strdup("live");
	tableau[1] = ft_strdup("ld");
	tableau[2] = ft_strdup("st");
	tableau[3] = ft_strdup("add");
	tableau[4] = ft_strdup("sub");
	tableau[5] = ft_strdup("and");
	tableau[6] = ft_strdup("or");
	tableau[7] = ft_strdup("xor");
	tableau[8] = ft_strdup("zjmp");
	tableau[9] = ft_strdup("ldi");
	tableau[10] = ft_strdup("sti");
	tableau[11] = ft_strdup("fork");
	tableau[12] = ft_strdup("lld");
	tableau[13] = ft_strdup("lldi");
	tableau[14] = ft_strdup("lfork");
	tableau[15] = ft_strdup("aff");
	tableau[16] = NULL;
	return (tableau);
}

int		in_tab(char *string, char **tableau)
{
	int		i;
	int		i2;

	i = 0;
	i2 = ft_strlen(string);
	if (string[i2 - 1] == ':')
		return (0);
	while (tableau[i])
	{
		if (ft_strncmp(string, tableau[i], ft_strlen(tableau[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		is_label(char *string)
{
	int		i;

	i = 0;
	if (string == NULL)
		return (0);
	while (string[i])
		i++;
	if (string[i - 1] == ':')
		return (1);
	return (0);
}

int		verif_ass(char *string)
{
	int		i;

	i = 0;
	while (string[i])
		i++;
	if (string[i - 1] != 's' && string[i - 2] != '.')
	{
		ft_putendl("Not a '.s' file.");
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_pars		*l2;
	t_print		*l3;
	t_header	*head;
	t_norme		n;

	head = malloc(sizeof(*head));
	head->magic = COREWAR_EXEC_MAGIC;
	n.tableau = fill_tab();
	if (ac != 2)
		return (error_arg());
	if (verif_ass(av[1]) == -1)
		return (-1);
	n.l = recup_file(av, head);
	if (n.l == NULL)
		return (error_arg());
	l2 = pars_begin(n.l, n.tableau);
	n.fd = ft_create(av[1]);
	l3 = to_print(l2, n.tableau, n.fd, head);
	return (0);
}
