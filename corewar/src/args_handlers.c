/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 18:41:07 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/11 18:48:54 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

t_bool	arg_dump(t_args_data *d, int *i, int ac, char const *const *av)
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

t_bool	arg_player(t_args_data *data, int *i, int ac, char const *const *av)
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

t_bool	arg_peek(t_args_data *data, int *i, int ac, char const *const *av)
{
	int num;

	(*i)++;
	if (*i >= ac)
		return (ft_putstr_fd("-peek require the Int.\n", 2), false);
	if (!ft_is_number(av[*i]))
		return (ft_putstr_fd("THIS IS NO NUMBER\n", 2), false);
	num = ft_atoi(av[*i]);
	data->peek = num;
	(*i)++;
	return (true);
}

t_bool	arg_color(t_args_data *data, int *i, int ac, char const *const *av)
{
	(void)ac;
	(void)av;
	(*i)++;
	data->color = true;
	return (true);
}
