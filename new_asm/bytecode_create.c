#include "asm.h"

t_bytecode *create_bytecode(t_inst *i)
{
  t_bytecode *b;

  b = (t_bytecode *)malloc(sizeof(t_bytecode));
  b->inst = i;
  b->next = NULL;
  return b;
}

t_inst *create_inst_op(int opcode)
{
  t_inst *ret;

  ret = (t_inst *)malloc(sizeof(t_inst));
  ret->value = opcode;
  ret->next = NULL;
  ret->size = 1;
  return ret;
}

t_inst *create_op(t_inst *head)
{
  t_inst *tmp;
  t_inst *tmp2;
  int *tab;
  int i;

  i = 0;
  tmp = head->next;
  tab = (int *)malloc(sizeof(10));
  ft_bzero(tab, 10);
  while (tmp)
  {
    tab[i] = tmp->type;
    tmp = tmp->next;
    i++;
  }
  tmp = head->next;
  tmp2 = create_inst_op(to_opcode(tab));
  head->next = tmp2;
  tmp2->next = tmp;
  return head;
}

t_bytecode *add_b(t_bytecode *head, t_bytecode *b)
{
  t_bytecode *tmp;
  if (!head)
    return b;
  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = b;
  return head;
}

t_bytecode  *add_bytecode(char *h, char *l, t_bytecode *head, int *count, int c)
{
  int i;
  char **tab;
  t_inst    *instruct;
  t_bytecode *b;

  rspaces(l);
  rspaces(h);
  tab = ft_strsplit(l, SEPARATOR_CHAR);
  if (count_tab(tab) < 1)
    no_arg(c);
  instruct = create_inst(h, -1, NULL, c);
  i = 0;
  while (tab[i])
  {
    instruct = add_inst(instruct, create_inst(tab[i], -1, instruct, c));
    i++;
  }
  check_grammar(instruct, c);
  if (instruct->opcode == 1)
    instruct = create_op(instruct);
  b = create_bytecode(instruct);
  instruct->where = *count;
  *count += len_list(instruct);
  return add_b(head, b);
}
