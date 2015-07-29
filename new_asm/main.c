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

int to_opcode(int *tab)
{
	int ret;
	int i;
	int i2;

	i = 7;
	ret = 0;
	i2 = 0;
	while (tab[i2])
	{
		if (tab[i2] == T_REG)
			ret = ret | (1 << (i - 1));
		else if (tab[i2] == T_IND)
		{
			ret = ret | (1 << (i));
			ret = ret | (1 << (i - 1));
		}
		else if (tab[i2] == T_DIR)
			ret = ret | (1 << (i));
		i -= 2;
		i2++;
	}
	return ret;
}

void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ' || *i == '\t')
      i++;
  }
  *i = 0;
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

int   len_list(t_inst *inst)
{
  t_inst *tmp;
  int i;

  i = 0;
  tmp = inst;
  while (tmp)
  {
    i += tmp->size;
    tmp = tmp->next;
  }
  return i;
}

t_bytecode  *add_bytecode(char *h, char *line, t_bytecode *head, int *count)
{
  int i;
  char **tab;
  t_inst    *instruction;
  t_bytecode *tmp;
  t_bytecode *b;

  RemoveSpaces(line);
  RemoveSpaces(h);
  tab = ft_strsplit(line, SEPARATOR_CHAR);
  ft_putendl("PUTINNNN");
  ft_putendl(line);
  instruction = create_inst(h, -1,NULL);
  i = 0;
  while (tab[i])
  {
    printf("COUCOU %s\n", tab[i]);
    instruction = add_inst(instruction, create_inst(tab[i], -1, instruction));
    i++;
  }
  check_grammar(instruction);
  if (instruction->opcode == 1)
    instruction = create_op(instruction);
  b = create_bytecode(instruction);
  instruction->where = *count;
  *count += len_list(instruction);
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
    tab[i][ft_strlen(tab[i]) - 1] = 0;
    i++;
    assembleur->label = add_label(assembleur->label, create_label(tab[0], assembleur->count));
  }
  if (count_tab(tab) < 2)
    return;
  printf("BORDELLLLL = %s\n", tab[count_tab(tab) - 1]);
  assembleur->bytecode = add_bytecode(tab[i], colle_tab(tab + (i+1)),assembleur->bytecode, &(assembleur->count));
  printf("FILE = %d\n", assembleur->count);
}

void print_label(t_label *l)
{
  t_label *t;

  t = l;
  while (t)
  {
    printf("LABEL = %s PLACE=%d\n", t->name, t->place);
    t = t->next;
  }
}

void print_i(t_inst *l)
{
  t_inst *t;

  t = l;
  while (t)
  {
    printf("STRING = %s WHERE = %d CODE = %d LABEL = %d VALUE = %d SIZE = %d\n", t->s, t->where, t->type, t->is_label, t->value, t->size);
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

void fill_label(t_asm *assembleur)
{
  t_bytecode *tmp;
  t_label *tmp2;
  t_inst *inst;

  tmp = assembleur->bytecode;
  while (tmp)
  {
    inst = tmp->inst;
    while (inst)
    {
      if (inst->is_label == 1)
      {
        tmp2 = assembleur->label;
        while (tmp2)
        {
          if (!ft_strcmp(tmp2->name, inst->s))
          {
            if (tmp2->place < tmp->inst->where)
              inst->value = (tmp2->place - tmp->inst->where);
            else
              inst->value = (tmp2->place - tmp->inst->where);
            break ;
          }
          tmp2 = tmp2->next;
        }
      }
      inst = inst->next;
    }
    tmp = tmp->next;
  }
}

int		ft_create(char *str)
{
	int		i;
	int		fd;

	i = 0;
	while (str[i] != 0)
		i++;
	str[i - 2] = 0;
	str = ft_strjoin(str, ".cor");
  printf("%s\n", str);
	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	return (fd);
}

void ft_put_fd(int fd, int t)
{
  write(fd, &t, 1);
}

void put_one(int value, int fd)
{
  ft_put_fd(fd, value);
}

void put_two(int value, int fd)
{
  ft_put_fd(fd, value >> 8);
  ft_put_fd(fd, value);
}

void put_four(int value, int fd)
{
  ft_put_fd(fd, value >> 24);
  ft_put_fd(fd, value >> 16);
  ft_put_fd(fd, value >> 8);
  ft_put_fd(fd, value);
}

void put_octet(int value, int size, int fd)
{
  if (size == 1)
    put_one(value, fd);
  else if (size == 2)
    put_two(value, fd);
  else if (size == 4)
    put_four(value, fd);
  return ;
}

int ft_putstr_fd2(char *s, int fd)
{
  int i;

  i = write(fd, s, ft_strlen(s));
  return (i);
}

void put_head(char *s, int len, int fd)
{
  int i;
  int c;

  i = 0;
  c = 0;
  i = ft_putstr_fd2(s, fd) - 1;
  while (i <= (len + 1))
  {
    write(fd, &c, 1);
    i++;
  }
}

void put_magic(int magic, int fd)
{
  ft_put_fd(fd, magic >> 24);
  ft_put_fd(fd, magic >> 16);
  ft_put_fd(fd, magic >> 8);
  ft_put_fd(fd, magic);
}

void put_count(int magic, int fd)
{
  ft_put_fd(fd, magic);
}

void put_to_file(char *name, t_bytecode * list, t_asm assembleur)
{
  int fd;
  t_inst *tmp;
  fd = ft_create(name);
  put_magic(COREWAR_EXEC_MAGIC, fd);
  put_head(assembleur.name, PROG_NAME_LENGTH + 1, fd);
  put_magic(assembleur.count, fd);
  printf("FUUUU %d\n", assembleur.count);
  put_head(assembleur.comment, COMMENT_LENGTH + 1, fd);
  while (list)
  {
    tmp = list->inst;
    while (tmp)
    {
      put_octet(tmp->value, tmp->size, fd);
      tmp = tmp->next;
    }
    list = list->next;
  }
  close(fd);
}

char *epur_space(char *l)
{
  int i;

  i = ft_strlen(l) - 1;
  while (*l && (*l == ' ' || *l == '\t'))
    l++;
  while (i && (l[i] == ' ' || l[i] == '\t'))
    l[i] = 0;
  return l;
}

char		*suppr_comment(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
  line = epur_space(line);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '#')
			break ;
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = ' ';
	tmp[i + 1] = '\0';
	return (tmp);
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
  assembleur.count = 0;
  while (get_next_line(fd, &line))
  {
    line = suppr_comment(line);
    if (line && line[0] != '.' && line[0] != COMMENT_CHAR)
    {
      tab = ft_strsplit(line, ';');
      parse_file(tab[0], &assembleur);
    }
    else if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
      assembleur.name = ft_get_head(line);
    else if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
      assembleur.comment = ft_get_head(line);
  }
  fill_label(&assembleur);
  print_inst(assembleur.bytecode);
  print_label(assembleur.label);
  put_to_file(av[1], assembleur.bytecode, assembleur);
  return (0);
}
