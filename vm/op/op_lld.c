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
	uint8_t		r;
	int16_t		loc;
	int8_t		acb;

	acb = cyc->mem[mem(pc->i + 1)].byte;
	if (cyc->mem[mem(pc->i + 1)].byte == 0x90)
	{
		r = cyc->mem[mem(pc->i + 6)].byte;
		if (reg(r))
			cw_memren(&pc->r[r], &cyc->mem[mem(pc->i + 2)], REG_SIZE);
		pc->i = mem(pc->i + 7);
		pc->carry = (pc->r[r]) ? 0 : 1;
	}
	else if (cyc->mem[mem(pc->i + 1)].byte == 0xd0)
	{
		r = cyc->mem[mem(pc->i + 4)].byte;
		cw_memren(&loc, &cyc->mem[mem(pc->i + 2)], IND_SIZE);
		if (reg(r))
			cw_memren(&pc->r[r], &cyc->mem[mem(pc->i + loc)], REG_SIZE);
		pc->i = mem(pc->i + 5);
		pc->carry = (pc->r[r]) ? 0 : 1;
	}
	else
		pc->i = mem(pc->i + acb_len(acb, 0));
}
