#include "asm.h"

int open_file(char *s)
{
  int fd;

  fd = open(s, O_RDONLY);
  if (fd == -1)
    return (-1);
  return (fd);
}

int main(int ac, char **av)
{
  int fd;

  if (ac < 2 || ac > 2)
    return (-1);
  if ((fd = open_file(av[1])) == -1)
    return (-1);
  essai();
  return (0);
}
