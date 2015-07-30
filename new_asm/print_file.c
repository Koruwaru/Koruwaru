#include "asm.h"

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

  if (!list)
    err_msg("No instructions", assembleur.line);
  fd = ft_create(name);
  put_magic(COREWAR_EXEC_MAGIC, fd);
  put_head(assembleur.name, PROG_NAME_LENGTH + 1, fd);
  put_magic(assembleur.count, fd);
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
