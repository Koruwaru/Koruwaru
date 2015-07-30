#include "asm.h"

void reg_find(char *s, t_inst *maillon, int c)
{
  s++;
  str_digit(s, c);
  maillon->type = T_REG;
  maillon->value = ft_atoi(s);
  maillon->size = 1;
}

void dir_found(char *s, t_inst *maillon, t_inst *head, int c)
{
  maillon->type = T_DIR;
  maillon->size = find_dir(head->value);
  if (s[1] == LABEL_CHAR)
  {
    s++;
    maillon->is_label = 1;
    maillon->value = -1;
  }
  else
  {
    s++;
    str_digit(s, c);
    maillon->value = ft_atoi(s);
  }
}

void indir_found(char *s, t_inst *maillon, int c)
{
  maillon->type = T_IND;
  maillon->size = 2;
  if (s[0] == LABEL_CHAR)
  {
    maillon->is_label = 1;
    maillon->value = -1;
  }
  else
  {
    str_digit(s, c);
    maillon->value = ft_atoi(s);
  }
}

void find_value(char *s, t_inst *maillon, t_inst *head, int c)
{
  if (s[0] == 'r')
    reg_find(s, maillon, c);
  else if (s[0] == DIRECT_CHAR)
    dir_found(s, maillon, head, c);
  else
    indir_found(s, maillon, c);
}
