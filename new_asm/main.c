#include "asm.h"

int open_file(char *s)
{
  int fd;

  fd = open(s, O_RDONLY);
  if (fd == -1)
    return (-1);
  return (fd);
}

t_bytecode *create_bytecode(t_inst *i)
{
  t_bytecode *b;

  b = (t_bytecode *)malloc(sizeof(t_bytecode));
  b->inst = i;
  b->next = NULL;
  return b;
}

void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

t_bytecode  *add_bytecode(char *h, char *line, t_bytecode *head)
{
  int i;
  char **tab;
  t_inst    *instruction;
  t_bytecode *tmp;
  t_bytecode *b;

  RemoveSpaces(line);
  RemoveSpaces(h);
  tab = ft_strsplit(line, SEPARATOR_CHAR);
  instruction = create_inst(h, -1,1);
  i = 0;
  while (tab[i])
  {
    instruction = add_inst(instruction, create_inst(tab[i], -1, 0));
    i++;
  }
  b = create_bytecode(instruction);
  if (!head)
    return b;
  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = b;
  return head;
}

void parse_file(char *l, t_asm *assembleur)
{
  char **tab;
  int i;

  i = 0;
  tab = ft_sp_strsplit(l);
  if (count_tab(tab) < 1)
    return ;
  if (tab[i][ft_strlen(tab[i]) - 1] == LABEL_CHAR)
  {
    i++;
    assembleur->label = add_label(assembleur->label, create_label(tab[0]));
  }
  if (count_tab(tab) < 2)
    return;
  assembleur->bytecode = add_bytecode(tab[i], colle_tab(tab + (i+1)),assembleur->bytecode);
}

void print_label(t_label *l)
{
  t_label *t;

  t = l;
  while (t)
  {
    printf("LABEL = %s\n", t->name);
    t = t->next;
  }
}

void print_i(t_inst *l)
{
  t_inst *t;

  t = l;
  while (t)
  {
    printf("STRING = %s\n", t->s);
    t = t->next;
  }
}

void print_inst(t_bytecode *l)
{
  t_bytecode *t;

  t = l;
  while (t)
  {
    printf("NEW INST = \n");
    print_i(t->inst);
    t = t->next;
  }
}

int main(int ac, char **av)
{
  int fd;
  char *line;
  char **tab;
  t_asm assembleur;

  if (ac < 2 || ac > 2)
    return (-1);
  if ((fd = open_file(av[1])) == -1)
    return (-1);
  assembleur.bytecode = NULL;
  assembleur.label = NULL;
  while (get_next_line(fd, &line))
  {
    if (line && line[0] != '.' && line[0] != COMMENT_CHAR)
    {
      tab = ft_strsplit(line, ';');
      parse_file(tab[0], &assembleur);
    }
  }
  print_inst(assembleur.bytecode);
  return (0);
}
