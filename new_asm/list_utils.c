#include "asm.h"

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
