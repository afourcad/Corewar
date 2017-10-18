/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:52:07 by gdelabro          #+#    #+#             */
/*   Updated: 2017/10/18 17:06:05 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_ram(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		ft_printf("%.2x%c", vm->ram[i], (i + 1) % 32 == 0 ? '\n' : ' ');
}