/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:32:46 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/09 19:28:53 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

static int		cmp_player(t_list *a, t_list *b)
{
	return (((t_player *)a->content)->id - ((t_player *)b->content)->id);
}

static t_bool	add_sorted_player(t_list **players, int id, char const *name)
{
	t_list			*elem;
	t_player_data	*new_player;

	new_player = (t_player_data *)malloc(sizeof(*new_player));
	new_player->filename = name;
	new_player->id = id;
	elem = ft_lstcreate((void *)new_player, sizeof(t_player_data));
	return (ft_lst_addsort(players, elem, 1, cmp_player));
}

static t_bool	arg_dump(t_args_data *d, int *i, int ac,
						char const *const *av)
{
	(*i)++;
	if (ft_is_number(av[*i]) && *i < ac)
	{
		if ((d->dump_cycles = ft_atoi(av[*i])) < 0)
		{
			ft_putstr_fd("Can't dump at negative cycle.\n", 2);
			return (false);
		}
	}
	else
	{
		ft_putstr_fd("-dump needs a number.\n", 2);
		return (false);
	}
	(*i)++;
	return (true);
}

static t_bool	arg_player(t_args_data *data, int *i, int ac,
						char const *const *av)
{
	int		pid;

	if (!ft_strcmp(av[*i], "-n"))
	{
		(*i)++;
		if (*i >= ac)
			return (ft_putstr_fd("-n must be followed by 1 int.\n", 2), false);
		if (!ft_is_number(av[*i]))
			return (ft_putstr_fd("Number no is number.\n", 2), false);
		pid = ft_atoi(av[*i]);
		if (pid >= data->next_player)
			data->next_player = pid + 1;
		(*i)++;
		if (*i >= ac)
			return (ft_putstr_fd("Where is player?\n", 2), false);
	}
	else
		pid = data->next_player++;
	if (!add_sorted_player(&data->players_data, pid, av[*i]))
		return (ft_putstr_fd("Two players have the same id.\n", 2), false);
	data->players_nb++;
	(*i)++;
	return (true);
}

static t_bool	arg_color(t_args_data *data, int *i, int ac,
						char const *const *av)
{
	(void)ac;
	(void)av;
	(*i)++;
	data->color = true;
	return (true);
}

t_bool			param_vm(t_args_data *data, int ac, char const *const *av)
{
	int				i;
	int				nbr;
	int				j;
	static t_bool	(*handlers[])(t_args_data *, int *,
									int, char const *const *) = {
		arg_dump, arg_color, NULL, arg_player
	};
	static char		options[][10] = {
		"-dump", "-color", "-peek", ""
	};

	nbr = 0;
	data->dump_cycles = -1;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < 3 && ft_strcmp(av[i], options[j]) != 0)
			j++;
		if (!handlers[j](data, &i, ac, av))
			return (false);
	}
	return (true);
}
