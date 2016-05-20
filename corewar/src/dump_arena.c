/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 13:40:17 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/11 18:40:17 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "vm_protos.h"

static void	ctoah(unsigned char byte, char ret[2])
{
	int					i;
	static const char	hexa[] = "0123456789abcdef";

	i = byte % 16;
	ret[1] = hexa[i];
	i = (byte - i) / 16;
	ret[0] = hexa[i];
}

static void	addr(unsigned int addr, char ret[9])
{
	ret[0] = '0';
	ret[1] = 'x';
	ctoah((addr >> 8) & 0xFF, ret + 2);
	ctoah((addr >> 0) & 0xFF, ret + 4);
	ret[6] = ' ';
	ret[7] = ':';
	ret[8] = ' ';
}

static void	print_byte(t_vm const *vm, char const *b, int pos, t_bool col)
{
	t_node				*processes;
	char				buff[2];
	char const			proc_col[] = "\033[44m";
	char const			reset_col[] = "\033[0m";
	char const			code_col[] = "\033[1;31m";

	processes = vm->processes;
	if (col)
	{
		if (*b != 0)
			write(1, code_col, sizeof(code_col));
		while (processes)
		{
			if (((t_process *)processes->content)->pc == (size_t)pos)
			{
				write(1, proc_col, sizeof(proc_col));
				break ;
			}
			processes = processes->next;
		}
	}
	ctoah(*b, buff);
	write(1, buff, sizeof(buff));
	ft_putstr(" ");
	write(1, reset_col, sizeof(reset_col));
}

void		dump_data(t_vm const *vm, size_t size, size_t line_s, t_bool col)
{
	char		a[9];
	char const	*tmp;
	size_t		i;
	size_t		j;

	i = 0;
	tmp = vm->arena.mem;
	ft_putstr("\033[1;1H\033[2J");
	while (i < size)
	{
		j = 0;
		addr(i, a);
		write(1, a, sizeof(a));
		while (j != line_s && i + j != size)
		{
			print_byte(vm, tmp, i + j, col);
			j++;
			tmp++;
		}
		i += line_s;
		ft_putstr("\n");
	}
}
