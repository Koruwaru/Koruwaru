#include "asm.h"

int to_opcode(int *tab)
{
	int ret;
	int i;
	int i2;

	i = 7;
	ret = 0;
	i2 = 0;
	while (tab[i2])
	{
		if (tab[i2] == T_REG)
			ret = ret | (1 << (i - 1));
		else if (tab[i2] == T_IND)
		{
			ret = ret | (1 << (i));
			ret = ret | (1 << (i - 1));
		}
		else if (tab[i2] == T_DIR)
			ret = ret | (1 << (i));
		i -= 2;
		i2++;
	}
	return ret;
}
