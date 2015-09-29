/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:32:46 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/29 21:34:43 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

static int		cmp_player(t_list *_1, t_list *_2)
{
	return (_1->id - _2->id);
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

t_bool			arg_dump(t_args_data *data, int *i, int ac, char const **av)
{
	(*i)++;
	if (ft_is_number(av[*i]))
	{
		if ((data->dump_cycles = ft_atoi(av[*i]) < 0))
		{
			ft_putstr_fd(2, "Can't dump at negative cycle.");
			return (false);
		}
	}
	else
	{
		ft_putstr_fd(2, "-dump needs a number.");
		return (false);
	}
	return (true);
}

t_bool			arg_player(t_args_data *data, int *i, int ac, char const **av)
{
	int		pid;

	if (!ft_strcmp(av[*i], "-n"))
	{
		(*i)++;
		if (*i >= ac)
		{
			ft_putstr_fd(2, "-n must be followed by some integer.");
			return (false);
		}
		if (!ft_is_number(av[*i]))
		{
			ft_putstr_fd(2, "Number no is number.");
			return (false);
		}
		pid = ft_atoi(av[*i]);
		if (pid > data->next_player)
			data->next_player = pid + 1;
		(*i)++;
	}
	else
		pid = data->next_player++;
	if (!add_sorted_player(&players, pid, av[*i]))
	{
		ft_putstr_fd(2, "Two player have the same id.");
		return (false);
	}
	data->players_nb++;
	return (true);
}

t_bool			param_vm(t_args_data *data, int ac, char const **av)
{
	t_list		*players_data;
	int			i;
	int			nbr;
	int			get_nbr;

	nbr = 0;
	args->dump_cycles = -1;
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
