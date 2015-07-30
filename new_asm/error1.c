#include "asm.h"

void bad_argument()
{
  ft_putendl("Not enough | Too much argument/s");
  exit(0);
}

void open_fail()
{
  ft_putendl("Error while trying to open asm file");
  exit(0);
}

void no_arg(int l)
{
  err_msg("No arg", l);
}

void bad_instruction(int l)
{
  err_msg("Bad instruction", l);
}

void arg_missing(int l)
{
  err_msg("Instruction without args", l);
}
