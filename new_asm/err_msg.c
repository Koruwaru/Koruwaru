#include "asm.h"

void err_msg(char *msg, int l)
{
  ft_putstr(msg);
  ft_putstr(" on line ");
  ft_putnbr(l);
  ft_putchar('\n');
  exit(0);
}
