/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:06:30 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 18:07:14 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

// Au lieu de ça, ca prend 2 index
// et 1 registre, additionne les 2 premiers, traite ca comme une adresse,
// y lit une valeur de la taille d’un registre et la met dans le 3eme
void	ldi(t_vm *vm, t_process *process)
{
	(void)vm;
	(void)process;
}
