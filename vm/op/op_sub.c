/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:01:02 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:43:36 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_cyc *cyc, t_pc *pc)
{
	uint8_t	a;
	uint8_t	b;
	uint8_t	c;
	uint8_t	acb;

	acb = cyc->mem[mem(pc->i + 1)].byte;
	c = cyc->mem[mem(pc->i + 4)].byte;
	b = cyc->mem[mem(pc->i + 3)].byte;
	a = cyc->mem[mem(pc->i + 2)].byte;
	if (cyc->mem[mem(pc->i + 1)].byte == 0x54 && reg(a) && reg(b) && reg(c))
	{
		pc->r[c] = pc->r[a] - pc->r[b];
		pc->i = mem(pc->i + acb_len(acb, 0));
		pc->carry = (pc->r[c]) ? 0 : 1;
	}
	else
		pc->i = mem(pc->i + acb_len(acb, 0));
}
