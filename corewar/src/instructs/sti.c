/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:08:32 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:08:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Prend un registre, et deux index (potentiellement des registres).
// Additionne les deux derniers, utilise cette somme comme une adresse
// ou sera copiée la valeur du premier paramètre.
void		sti(t_vm *vm, t_process *process)
{
	size_t	reg;
	int		value;
	size_t	pc;

	// check if register exist
	reg = process->instruction.params[0];
	if (reg >= REG_NUMBER)
		return ; // else abort

	// get register value
	value = loadreg(&process->registers[reg]);

	// TODO reduce addition to pc addr
	// a -> T_ANY
	// b -> T_DIR | T_REG
	pc = 0; // 0xb(a + b) addr value in mem

	// copy register at pc position
	stomem(&vm->arena, &value, REG_SIZE, pc);
}
