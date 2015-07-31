#include "libft.h"
#include "vm_protos.h"

static size_t	get_param_size(char ocp, t_op const *op, int param_id)
{
	t_arg_type	param_type;
	size_t		param_s;

	param_s = 0;
	if (op->ocp == 0)
	{
		param_type = op->args_types[param_id];
	}
	else
	{
		param_type = get_param_type(ocp, param_id);
	}
	if (param_type & T_REG)
		param_s = 1;
	else if (param_type & T_IND)
		param_s = 2;
	else if (param_type & T_DIR)
	{
		if (op->ind_size == 0)
			param_s = 4;
		else
			param_s = 2;
	}
	return (param_s);
}

static size_t	get_instr_size(t_instruction *instr)
{
	size_t		nb;
	t_op const	*op;
	size_t		size;

	size = 1;
	op = get_op(instr->opcode);
	if (op->ocp)
	{
		size += 1;
	}
	nb = instr->nb_params;
	while (nb > 0)
	{
		size += get_param_size(instr->params_types, op, nb - 1);
		nb--;
	}
	return (size);
}

void	set_instr(t_instruction *instr, t_uint opcode, t_uint nb, t_arg_type ocp[MAX_ARGS_NUMBER],
				  t_uint params[MAX_ARGS_NUMBER])
{
	size_t		size;

	size = 0;
	instr->opcode = opcode;
	instr->nb_params = nb;
	instr->params_types = 0;
	ft_memcpy(instr->params, params, sizeof(instr->params));
	while (nb > 0)
	{
		instr->params_types |= ocp[nb - 1] << (6 - nb * 2);
		nb--;
	}
	instr->size = get_instr_size(instr);
}
