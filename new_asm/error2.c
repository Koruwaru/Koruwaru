#include "asm.h"

void error_parse(int l)
{
  err_msg("Error while parsing", l);
}

void bad_parameter(int l)
{
  err_msg("Bad parameter", l);
}

void bad_parameter_nb(int l)
{
  err_msg("Bad parameter number", l);
}
