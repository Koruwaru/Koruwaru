#include "libft.h"
#include "vm_protos.h"

void	set_instr(t_instruction *instr, t_uint nb, t_arg_type ocp,
				  t_uint params[MAX_ARGS_NUMBER])
{
	instr->nb_params = nb;
	instr->params_types = ocp;
	ft_memcpy(instr->params, params, sizeof(instr->params));
}
