#include "asm.h"

void init_asm(t_asm *a)
{
  a->bytecode = NULL;
  a->label = NULL;
  a->name = NULL;
  a->comment = NULL;
  a->count = 0;
  a->line = 0;
}

int		ft_create(char *str)
{
	int		i;
	int		fd;

	i = 0;
	while (str[i] != 0)
		i++;
	str[i - 2] = 0;
	str = ft_strjoin(str, ".cor");
  ft_putstr("Writing output program to ");
  ft_putendl(str);
	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	return (fd);
}

char *epur_space(char *l)
{
  int i;

  i = ft_strlen(l) - 1;
  while (*l && (*l == ' ' || *l == '\t'))
    l++;
  while (i && (l[i] == ' ' || l[i] == '\t'))
    l[i] = 0;
  return l;
}

char		*suppr_comment(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
  line = epur_space(line);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2));
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '#')
			break ;
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = ' ';
	tmp[i + 1] = '\0';
	return (tmp);
}

int open_file(char *s)
{
  int fd;

  fd = open(s, O_RDONLY);
  if (fd == -1)
    return (-1);
  return (fd);
}
