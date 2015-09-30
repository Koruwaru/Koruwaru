/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:32:46 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/30 16:57:41 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm_protos.h"
#include "libft.h"

static int		cmp_player(t_list *_1, t_list *_2)
{
	return (((t_player *)_1->content)->id - ((t_player *)_2->content)->id);
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

static t_bool	arg_dump(t_args_data *data, int *i, int ac, char const * const *av)
{
	(*i)++;
	if (ft_is_number(av[*i]) && *i < ac)
	{
		if ((data->dump_cycles = ft_atoi(av[*i])) < 0)
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

static t_bool	arg_player(t_args_data *data, int *i, int ac, char const * const *av)
{
	int		pid;

	if (!ft_strcmp(av[*i], "-n"))
	{
		(*i)++;
		if (*i >= ac)
		{
			ft_putstr_fd("-n must be followed by some integer.\n", 2);
			return (false);
		}
		if (!ft_is_number(av[*i]))
		{
			ft_putstr_fd("Number no is number.\n", 2);
			return (false);
		}
		pid = ft_atoi(av[*i]);
		if (pid >= data->next_player)
			data->next_player = pid + 1;
		(*i)++;
	}
	else
		pid = data->next_player++;
	if (!add_sorted_player(&data->players_data, pid, av[*i]))
	{
		ft_putstr_fd("Two player have the same id.\n", 2);
		return (false);
	}
	data->players_nb++;
	(*i)++;
	return (true);
}

t_bool			param_vm(t_args_data *data, int ac, char const * const *av)
{
	int			i;
	int			nbr;

	nbr = 0;
	data->dump_cycles = -1;
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (!arg_dump(data, &i, ac, av))
				return (false);
		}
		else
		{
			if (!arg_player(data, &i, ac, av))
				return (false);
		}
	}
	return (true);
}
