#include "asm.h"

t_label *create_label(char *s, int place)
{
  t_label *label;

  label = (t_label *)malloc(sizeof(t_label));
  label->name = ft_strdup(s);
  if (place)
    label->place = place;
  label->next = NULL;
  return label;
}

void check_label(t_label *h, t_label *m)
{
  t_label *tmp;

  tmp = h;
  while (tmp)
  {
    if (!ft_strcmp(h->name, m->name))
    {
      ft_putendl("Redefinition of label");
      exit(0);
    }
    tmp = tmp->next;
  }
}

t_label *add_label(t_label *head, t_label *maillon)
{
  t_label *tmp;

  if (!head)
    return maillon;
  tmp = head;
  check_label(head, maillon);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = maillon;
  return head;
}

void find_value(char *s, t_inst *maillon, t_inst *head)
{
  if (s[0] == 'r')
  {
    s++;
    maillon->type = T_REG;
    maillon->value = atoi(s);
    maillon->size = 1;
  }
  else if (s[0] == DIRECT_CHAR)
  {
    maillon->type = T_DIR;
    maillon->size = find_dir(head->value);
    if (s[1] == LABEL_CHAR)
    {
      s++;
      maillon->is_label = 1;
      maillon->value = -1;
    }
    else
    {
      s++;
      maillon->value = atoi(s);
    }
  }
  else
  {
    maillon->type = T_IND;
    maillon->size = 2;
    if (s[0] == LABEL_CHAR)
    {
      maillon->is_label = 1;
      maillon->value = -1;
    }
    else
      maillon->value = atoi(s);
  }
}

t_inst  *create_inst(char *s, int where, t_inst *head)
{
  t_inst *maillon;

  maillon = (t_inst *)malloc(sizeof(t_inst));
  maillon->is_label = 0;
  maillon->where = -1;
  maillon->s = ft_strdup(erase_char(s));
  maillon->opcode = 0;
  if (!head)
  {
    maillon->value = find_opcode(s);
    maillon->size = 1;
    if (maillon->value == -1)
    {
      printf("POURQUOI ??? %s\n", s);
      exit(0);
    }
    maillon->opcode = is_op(maillon->value);
  }
  else
    find_value(s, maillon, head);
  maillon->where = where;
  maillon->next = NULL;
  return maillon;
}

t_inst *add_inst(t_inst *head, t_inst *maillon)
{
  t_inst *tmp;

  if (!head)
    return maillon;
  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = maillon;
  return head;
}

int   count_inst(t_inst *h)
{
  t_inst *tmp;
  int i;

  i = 0;
  tmp = h;
  if (!h)
    return 0;
  while (tmp)
  {
    i++;
    tmp = tmp->next;
  }
  return i;
}
