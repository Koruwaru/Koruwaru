#include "asm.h"

void rspaces(char* source)
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

char *give_name(char *s, t_asm a)
{
  if (!a.name)
    return ft_get_head(s);
  else
    err_msg("Name already present", a.line);
  return (NULL);
}

char *give_comment(char *s, t_asm a)
{
  if (!a.comment)
    return ft_get_head(s);
  else
    err_msg("Comment already present", a.line);
  return (NULL);
}
