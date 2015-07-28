#include "asm.h"
int count_tab(char **tab)
{
  int i;

  i = 0;
  if (!tab)
    return 0;
  while (tab[i])
    i++;
  return i;
}

int count_all_tab(char **tab)
{
  int i;
  int i2;

  i = 0;
  i2 = 0;
  while (tab[i])
  {
    while (tab[i][i2])
      i2++;
    i++;
  }
  return i2 + i;
}

char *colle_tab(char **tab)
{
  char *s;
  int i;
  int i2;
  int i3;

  i = 0;
  i2 = 0;
  i3 = 0;
  s = (char *)malloc(sizeof(count_all_tab(tab)) + 1);
  while (tab[i])
  {
    while (tab[i][i2])
    {
      s[i3] = tab[i][i2];
      i2++;
      i3++;
    }
    i2 = 0;
    i++;
  }
  s[i3] = '\0';
  return s;
}
