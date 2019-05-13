/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:00:06 by jochang           #+#    #+#             */
/*   Updated: 2019/05/04 00:33:42 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_cyc *cyc, t_pc *pc)
{
	uint8_t		reg;
	int16_t		loc;
	int8_t		acb;

	acb = cyc->mem[MEM(pc->i + 1)].byte;
	if (cyc->mem[MEM(pc->i + 1)].byte == 0x90)
	{
		reg = cyc->mem[MEM(pc->i + 6)].byte;
		if (REG(reg))
			cw_memren(&pc->r[reg], &cyc->mem[MEM(pc->i + 2)], REG_SIZE);
		pc->i = MEM(pc->i + 7);
		pc->carry = (pc->r[reg]) ? 0 : 1;
	}
	else if (cyc->mem[MEM(pc->i + 1)].byte == 0xd0)
	{
		reg = cyc->mem[MEM(pc->i + 4)].byte;
		cw_memren(&loc, &cyc->mem[MEM(pc->i + 2)], IND_SIZE);
		if (REG(reg))
			cw_memren(&pc->r[reg], &cyc->mem[MEM(pc->i + loc)], REG_SIZE);
		pc->i = MEM(pc->i + 5);
		pc->carry = (pc->r[reg]) ? 0 : 1;
	}
	else
		pc->i = MEM(pc->i + acb_len(acb, 0));
}