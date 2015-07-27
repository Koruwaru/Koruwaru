#ifndef ASM_H
# define ASM_H

# include "op.h"
#include "../common/libft/includes/libft.h"
#include <stdio.h> ///////////////
#include <fcntl.h>
#include "get_next_line.h"

enum {
  INST,
  REG,
  DIRECT,
  INDIRECT
};

void essai();

#endif
