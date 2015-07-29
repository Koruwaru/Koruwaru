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
  char *ret;
  int i;

  i = 0;
  ret = NULL;
  while (tab[i])
  {
    ret = ft_strjoin(ret, tab[i]);
    i++;
  }
  return ret;
}

char *erase_char(char *s)
{
  while (*s && (*s == ':' || *s == '%'))
    s++;
  return s;
}

char		*ft_get_head(char *line)
{
	char	*str;
  int i;

  i = 0;
	while (*line && *line != '"')
		line++;
	line++;
  while (line[i])
  {
    if (line[i] == '"')
    {
      line[i] = 0;
      break ;
    }
    i++;
  }
	str = ft_strndup(line, ft_strlen(line));
	return (str);
}

char		*ft_strndup(char *line, int n)
{
	char	*str;
	int		i = 0;

	str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (n && line[i])
	{
		str[i] = line[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}
