/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:44 by jochang           #+#    #+#             */
/*   Updated: 2019/05/08 03:49:02 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	first_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *loc)
{
	if (((acb >> 6) & 3) == REG_CODE)
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

static uint8_t	second_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *tmp)
{
	if (((acb >> 4) & 3) == REG_CODE)
		*tmp = pc->r[cyc->mem[MEM(pc->i + 2 + ACB_ARG_1((acb >> 6) & 3))].byte];
	else if (((acb >> 4) & 3) == DIR_CODE || ((acb >> 4) & 3) == IND_CODE)
		cw_memren(tmp,
					&cyc->mem[MEM(pc->i + 2 + ACB_ARG_1((acb >> 4) & 3))],
					IND_SIZE);
	else
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

void			op_ldi(t_cyc *cyc, t_pc *pc)
{
	int32_t		loc;
	int32_t		tmp;
	uint8_t		acb;

	loc = 0;
	tmp = 0;
	acb = cyc->mem[MEM(pc->i + 1)].byte;
	RETURN_CHECK(!first_check(cyc, pc, acb, &loc));
	RETURN_CHECK(!second_check(cyc, pc, acb, &tmp));
	loc += tmp;
	tmp = cyc->mem[MEM(pc->i + acb_len(acb, 1) - 1)].byte;
	if (REG(tmp))
	{
		cw_memren(&pc->r[tmp],
					&cyc->mem[MEM(pc->i + IDX((int16_t)loc))],
					REG_SIZE);
		pc->carry = loc ? 0 : 1;
	}
	pc->i = MEM(pc->i + acb_len(acb, 1));
}
