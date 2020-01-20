/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:58:58 by jochang           #+#    #+#             */
/*   Updated: 2019/05/08 22:02:32 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_cyc *cyc, t_pc *pc)
{
	uint8_t	a;
	uint8_t	b;
	uint8_t	c;
	uint8_t	acb;

	acb = cyc->mem[mem(pc->i + 1)].byte;
	a = cyc->mem[mem(pc->i + 2)].byte;
	b = cyc->mem[mem(pc->i + 3)].byte;
	c = cyc->mem[mem(pc->i + 4)].byte;
	if ((acb == 0x54 || acb == 0x55 || acb == 0x56 || acb == 0x57) &&
		reg(a) && reg(b) && reg(c))
	{
		pc->r[c] = pc->r[b] + pc->r[a];
		pc->i = mem(pc->i + acb_len(acb, 0));
		pc->carry = pc->r[c] ? 0 : 1;
	}
	else
		pc->i = mem(pc->i + acb_len(acb, 0));
}
