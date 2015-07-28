#include "asm.h"

t_label *create_label(char *s)
{
  t_label *label;

  label = (t_label *)malloc(sizeof(t_label));
  label->name = ft_strdup(s);
  label->place = -1; //// POUR l'instant
  label->next = NULL;
  return label;
}

t_label *add_label(t_label *head, t_label *maillon)
{
  t_label *tmp;

  if (!head)
    return maillon;
  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = maillon;
  return head;
}

void find_value(char *s, t_inst *maillon)
{
  if (s[0] == 'r')
  {
    s++;
    maillon->type = T_REG;
    maillon->value = atoi(s);
  }
  else if (s[0] == DIRECT_CHAR)
  {
    maillon->type = T_DIR;
    if (s[1] == LABEL_CHAR)
    {
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
    if (s[0] == LABEL_CHAR)
    {
      maillon->is_label = 1;
      maillon->value = -1;
    }
    else
      maillon->value = atoi(s);
  }
}

t_inst  *create_inst(char *s, int where, int is_head)
{
  t_inst *maillon;

  maillon = (t_inst *)malloc(sizeof(t_inst));
  maillon->is_label = 0;
  maillon->where = -1;
  maillon->s = ft_strdup(s);
  if (is_head)
  {
    maillon->value = find_opcode(s);
    if (maillon->value == -1)
    {
      printf("POURQUOI ??? %s\n", s);
      exit(0);
    }
  }
  else
    find_value(s, maillon);
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
