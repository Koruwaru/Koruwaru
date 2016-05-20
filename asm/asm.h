/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:15:24 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:45:31 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../common/libft/include/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct			s_inst
{
	int					type;
	int					is_label;
	int					value;
	int					where;
	char				*s;
	int					size;
	int					opcode;
	struct s_inst		*next;
}						t_inst;

typedef struct			s_bytecode
{
	t_inst				*inst;
	struct s_bytecode	*next;
}						t_bytecode;

typedef struct			s_label
{
	char				*name;
	struct s_label		*next;
	int					place;
}						t_label;

typedef struct			s_asm
{
	t_bytecode			*bytecode;
	t_label				*label;
	int					count;
	char				*name;
	char				*comment;
	int					line;
}						t_asm;

int						find_opcode(char *s);
char					**ft_sp_strsplit(char const *s);
int						count_tab(char **tab);
t_label					*create_label(char *s, int p);
t_label					*add_label(t_label *head, t_label *maillon, int c);
t_inst					*add_inst(t_inst *head, t_inst *maillon);
t_inst					*create_inst(char *s, int where, t_inst *h, int c);
char					*colle_tab(char **tab);
int						count_inst(t_inst *h);
void					check_grammar(t_inst *instruction, int c);
int						is_op(int opcode);
int						find_dir(int opcode);
char					*erase_char(char *s);
char					*ft_strndup(char *line, int n);
char					*ft_get_head(char *line, int fd);
void					str_digit(char *s, int c);
void					init_asm(t_asm *a);
void					put_octet(int value, int size, int fd);
void					put_head(char *s, int len, int fd);
void					put_magic(int magic, int fd);
void					put_count(int magic, int fd);
void					put_to_file(char *name, t_bytecode *list, t_asm ass);
void					ft_put_fd(int fd, int t);
void					put_one(int value, int fd);
void					put_two(int value, int fd);
void					put_four(int value, int fd);
int						ft_putstr_fd2(char *s, int fd);
int						ft_create(char *str);
char					*epur_space(char *l);
char					*suppr_comment(char *line);
int						open_file(char *s);
void					rspaces(char *s);
void					no_arg();
t_bytecode				*add_bytecode(char **l,\
		t_bytecode *he, int *co, int c);
int						to_opcode(int *tab);
int						len_list(t_inst *inst);
void					fill_label(t_asm *assembleur);
void					parse_file(char *l, t_asm *assembleur);
void					bad_argument();
void					open_fail();
void					find_value(char *s, t_inst *m, t_inst *head, int c);
void					bad_instruction(int c);
void					arg_missing(int c);
void					error_parse(int c);
void					bad_parameter(int c);
void					bad_parameter_nb(int c);
void					err_msg(char *msg, int l);
char					*give_comment(char *s, t_asm a, int fd);
char					*give_name(char *s, t_asm a, int fd);
char					*lets_read(int fd);
char					*remove_quote(char *s);

#endif
