/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 18:32:46 by tmielcza          #+#    #+#             */
/*   Updated: 2015/09/22 19:29:43 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "libft.h"

static int		cmp_player(t_list *)
{
	return ();
}

static void		param_player(t_list **players, t_list **programs,
							 const char *name, int nbr)
{
	void		*data;
	size_t		fsize;
	size_t		progsize;
	t_list		*elem;

	data = get_file_data|(name, &fsize);
	elem = ft_lstcreate(create_player(nbr, ((t_header *)data)->prog_name), sizeof(t_player));
	ft_lst_addsort(players, elem, 1, cmp_player);
	ft_lstpush(get_program(data, fsize, &progsize), progsize);
}

int				param_vm(t_vm *vm, int ac, char const **av)
{
	int		i;
	int		nbr;
	int		get_nbr;

	nbr = -1;
	vm->dump_cycle = -1;
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			i++;
			if (ft_is_number(av[i]))
			{
				if ((vm->dump_cycle = ft_atoi(av[i]) < 0)
					return (-1);
			}
			else
				return (-1);
		}
		else if (ft_strcmp(av[i], "-n"))
		{
			i++;
			nbr--;
			if (ft_is_number(av[i]))
			{
				if ((get_nbr = ft_atoi(av[i])) >= 0)
				{
					i++;
					param_player(&vm->players, &vm->programs, av[i], get_nbr);
				}
				else
					return (-1);
			}
			else
				return (-1);
			i++;
			param_player(&vm->players, &vm->programs, av[i], nbr);
		}
		else
		{
			nbr--;
			param_player(&vm->players, &vm->programs, av[i], nbr);
		}
		i++;
	}
	return (0);
}
