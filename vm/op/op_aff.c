/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:07 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:39:36 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_cyc *cyc, t_pc *pc)
{
	uint32_t	chr;
	uint8_t		acb;

	acb = cyc->mem[MEM(pc->i + 1)].byte;
	if (cyc->mem[MEM(pc->i + 1)].byte == 0x40)
	{
		chr = pc->r[cyc->mem[MEM(pc->i + 2)].byte];
		ft_putchar(ft_isprint(chr) ? chr : '!');
		pc->i = MEM(pc->i + 3);
	}
	else
		pc->i = MEM(pc->i + 2);
}
