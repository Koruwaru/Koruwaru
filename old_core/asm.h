/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 17:59:27 by jyim              #+#    #+#             */
/*   Updated: 2014/02/02 23:31:00 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <libft.h>
# include <fcntl.h>
# include "op.h"

# define PARAM 0
# define INSTR 1
# define LABEL 2

typedef struct			s_lex
{
	char				*s;
	struct s_lex		*next;
	struct s_lex		*prev;
}						t_lex;

typedef struct			s_pars
{
	int					islab;
	char				*label;
	char				**cmd;
	struct s_pars		*prev;
	struct s_pars		*next;
}						t_pars;

typedef struct			s_print
{
	unsigned char						op;
	unsigned char						enc;
	unsigned char					param;
	struct s_print		*next;
}						t_print;

typedef struct			s_norme
{
	char				**tableau;
	t_lex				*l;
	int					fd;
}						t_norme;

char	**ft_sp_strsplit(char const *s);
t_lex	*recup_file(char **av, t_header *head);
t_lex	*end_l(t_lex *l, char *string);
void	aff_list(t_lex *l);
t_lex	*fill_mem(t_lex *l);
int		in_tab(char *string, char **tableau);
t_lex	*fill_param(t_lex *l, char **tab1);
int		is_label(char *string);
int		count_tab(char **tab);
char	**cpy_tab(char **tab);
t_pars	*pars_begin(t_lex *l, char **tableau);
t_pars	*pars_lab(t_pars *l, char *string);
t_pars	*end_l_pars(t_pars *l, char **tab, char *string, int i);
t_print	*to_print(t_pars *l, char **tab, int fd, t_header *head);
int		put_unsigned_char_fd(int fd, unsigned char c);
int		ft_create(char *str);
int		error_arg(void);
void	to_print2(int fd, int param, int i, char **tab);
void	to_print3(int fd, int param, int i, char **tab);

#endif
