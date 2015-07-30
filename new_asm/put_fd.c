#include "asm.h"

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

int ft_putstr_fd2(char *s, int fd)
{
  int i;

  i = write(fd, s, ft_strlen(s));
  return (i);
}
