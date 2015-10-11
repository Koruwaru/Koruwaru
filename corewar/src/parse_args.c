/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:32:46 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/11 18:48:13 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

static int		cmp_player(t_list *a, t_list *b)
{
	return (((t_player *)a->content)->id - ((t_player *)b->content)->id);
}

t_bool			add_sorted_player(t_list **players, int id, char const *name)
{
	t_list			*elem;
	t_player_data	*new_player;

	new_player = (t_player_data *)malloc(sizeof(*new_player));
	new_player->filename = name;
	new_player->id = id;
	elem = ft_lstcreate((void *)new_player, sizeof(t_player_data));
	return (ft_lst_addsort(players, elem, 1, cmp_player));
}

t_bool			param_vm(t_args_data *data, int ac, char const *const *av,

						t_opt_handler norme)
{
	int						i;
	int						nbr;
	int						j;
	static t_opt_handler	handlers[] =
	{arg_dump, arg_color, arg_peek, arg_player};
	static char				options[][10] = {"-dump", "-color", "-peek", ""};

	nbr = 0;
	data->dump_cycles = -1;
	data->peek = -1;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < 3 && ft_strcmp(av[i], options[j]) != 0)
			j++;
		if ((norme = handlers[j]) && !(*norme)(data, &i, ac, av))
			return (false);
	}
	return (true);
}
