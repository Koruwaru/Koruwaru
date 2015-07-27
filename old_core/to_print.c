/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:30:21 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:31:55 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

int					find_opcode(char **tab, char *string)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], string) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

t_print				*print_end(t_print *l, int op)
{
	t_print		*tmp;
	t_print		*tmp2;

	tmp = l;
	tmp2 = (t_print *)malloc(sizeof(t_print));
	tmp2->next = NULL;
	tmp2->op = (unsigned char)op;
	if (l == NULL)
		return (tmp2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	return (tmp2);
}

int					which_param(char *s)
{
	if (s[0] == 'r')
		return (2);
	else if (s[0] == DIRECT_CHAR)
	{
		if (s[1] == LABEL_CHAR)
			return (3);
		return (1);
	}
	else
		return (0);
}

unsigned char		to_encode(char **tab)
{
	int					i;
	int					param;
	unsigned char		encod;

	i = 1;
	encod = 0;
	while (tab[i])
	{
		param = which_param(tab[i]);
		if (param == 0)
			encod = (0xC0 >> ((i - 1) * 2)) | encod;
		else if (param == 2)
			encod = (0x40 >> ((i - 1) * 2)) | encod;
		else
			encod = (0x80 >> ((i - 1) * 2)) | encod;
		i++;
	}
	return (encod);
}

int					to_param(char **tab, int fd)
{
	int					i;
	int					param;
	int					tern;

	i = 1;
	param = 0;
	while (tab[i])
	{
		param = 0;
		tern = which_param(tab[i]);
		if (tern == 0)
		{
			param = ft_atoi(tab[i]);
			put_unsigned_char_fd(fd, param >> 8);
			put_unsigned_char_fd(fd, param);
		}
		else if (tern == 1)
			to_print2(fd, param, i, tab);
		else
			to_print3(fd, param, i, tab);
		i++;
	}
	return (param);
}
#include <stdio.h>
void				print_header(int fd, t_header *head)
{
	int				i;

	ft_putchar('\t');
	ft_putendl(head->prog_name);
	ft_putchar('\t');
	ft_putendl(head->comment);
	put_unsigned_char_fd(fd, head->magic >> 24);
	put_unsigned_char_fd(fd, head->magic >> 16);
	put_unsigned_char_fd(fd, head->magic >> 8);
	put_unsigned_char_fd(fd, head->magic);
	printf("%x\n", head->magic);
	i = ft_putstr_fd(head->prog_name, fd);
	while (i < PROG_NAME_LENGTH)
	{
		put_unsigned_char_fd(fd, 0);
		i++;
	}
	i = ft_putstr_fd(head->comment, fd);
	while (i < COMMENT_LENGTH)
	{
		put_unsigned_char_fd(fd, 0);
		i++;
	}
}


t_print				*to_print(t_pars *l, char **tableau, int fd, t_header *head)
{
	t_pars				*tmp;
	t_print				*tmp2;
	int					opcode;
	int					encod;
	int					param;

	opcode = 0;
	tmp = l;
	tmp2 = NULL;
	print_header(fd, head);
	while (tmp)
	{
		opcode = find_opcode(tableau, tmp->cmd[0]);
		encod = to_encode(tmp->cmd);
		put_unsigned_char_fd(fd, opcode);
		put_unsigned_char_fd(fd, encod);
		param = to_param(tmp->cmd, fd);
		tmp2 = print_end(tmp2, opcode);
		tmp = tmp->next;
	}
	return (tmp2);
}
