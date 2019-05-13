/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:00:14 by jochang           #+#    #+#             */
/*   Updated: 2019/05/04 00:34:55 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	first_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *loc)
{
	if ((acb >> 6) == REG_CODE)
		*loc = pc->r[cyc->mem[MEM(pc->i + 2)].byte];
	else if ((acb >> 6) == DIR_CODE || (acb >> 6) == IND_CODE)
		cw_memren(loc, &cyc->mem[MEM(pc->i + 2)], IND_SIZE);
	else
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

static uint8_t	second_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *loc)
{
	int32_t	tmp;

	tmp = 0;
	if ((acb & 0x30) == (REG_CODE << 4))
		*loc += pc->r[cyc->mem[MEM(pc->i + 2 + ACB_ARG_1(acb >> 6))].byte];
	else if (((acb & 0x30) == (DIR_CODE << 4)) ||
			((acb & 0x30) == (IND_CODE << 4)))
		cw_memren(&tmp,
					&cyc->mem[MEM(pc->i + 2 + ACB_ARG_1(acb >> 6))],
					IND_SIZE);
	else
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	*loc += tmp;
	return (1);
}

void			op_lldi(t_cyc *cyc, t_pc *pc)
{
	int32_t		loc;
	int32_t		tmp;
	uint8_t		acb;

	loc = 0;
	tmp = 0;
	acb = cyc->mem[MEM(pc->i + 1)].byte;
	RETURN_CHECK(!first_check(cyc, pc, acb, &loc));
	RETURN_CHECK(!second_check(cyc, pc, acb, &loc));
	tmp = cyc->mem[MEM(pc->i + acb_len(acb, 1) - 1)].byte;
	if (REG(tmp))
	{
		cw_memren(&pc->r[tmp], &cyc->mem[MEM(pc->i + (int16_t)loc)], REG_SIZE);
		pc->i = MEM(pc->i + acb_len(acb, 1));
		pc->carry = (pc->r[tmp]) ? 0 : 1;
	}
	else
		pc->i = MEM(pc->i + acb_len(acb, 1));
}
