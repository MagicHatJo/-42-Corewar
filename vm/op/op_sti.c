/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:00:55 by jochang           #+#    #+#             */
/*   Updated: 2019/05/08 03:49:10 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	first_check(t_cyc *cyc, t_pc *pc, uint8_t acb)
{
	if (((acb >> 6) & 3) != REG_CODE || !REG(cyc->mem[MEM(pc->i + 2)].byte))
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

static uint8_t	second_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int16_t *loc)
{
	if (((acb >> 4) & 3) == REG_CODE)
		*loc = pc->r[cyc->mem[MEM(pc->i + 3)].byte];
	else if (((acb >> 4) & 3) == DIR_CODE || ((acb >> 4) & 3) == IND_CODE)
		cw_memren(loc, &cyc->mem[MEM(pc->i + 3)], IND_SIZE);
	else
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

static uint8_t	third_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int16_t *loc)
{
	int16_t	tmp;

	tmp = 0;
	if (((acb >> 2) & 3) == REG_CODE)
		tmp = pc->r[cyc->mem[MEM(pc->i + 3 + ACB_ARG_1((acb >> 4) & 3))].byte];
	else if (((acb >> 2) & 3) == DIR_CODE || ((acb >> 2) & 3) == IND_CODE)
		cw_memren(&tmp,
					&cyc->mem[MEM(pc->i + 3 + ACB_ARG_1((acb >> 4) & 3))],
					IND_SIZE);
	else
	{
		pc->i = MEM(pc->i + acb_len(acb, 1));
		return (0);
	}
	*loc += tmp;
	return (1);
}

void			op_sti(t_cyc *cyc, t_pc *pc)
{
	int16_t		loc;
	uint8_t		acb;

	loc = 0;
	acb = cyc->mem[MEM(pc->i + 1)].byte;
	RETURN_CHECK(!first_check(cyc, pc, acb));
	RETURN_CHECK(!second_check(cyc, pc, acb, &loc));
	RETURN_CHECK(!third_check(cyc, pc, acb, &loc));
	cw_memwen(&cyc->mem[MEM(pc->i + IDX((int16_t)loc))],
				&pc->r[cyc->mem[MEM(pc->i + 2)].byte], REG_SIZE, pc->r[0]);
	pc->i = MEM(pc->i + acb_len(acb, 1));
}
