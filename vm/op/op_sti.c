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
	if (((acb >> 6) & 3) != REG_CODE || !reg(cyc->mem[mem(pc->i + 2)].byte))
	{
		pc->i = mem(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

static uint8_t	second_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int16_t *loc)
{
	int8_t	tmp;

	if (((acb >> 4) & 3) == REG_CODE)
	{
		tmp = cyc->mem[mem(pc->i + 3)].byte;
		*loc = reg(tmp) ? pc->r[tmp] : 0;
	}
	else if (((acb >> 4) & 3) == DIR_CODE || ((acb >> 4) & 3) == IND_CODE)
		cw_memren(loc, &cyc->mem[mem(pc->i + 3)], IND_SIZE);
	else
	{
		pc->i = mem(pc->i + acb_len(acb, 1));
		return (0);
	}
	return (1);
}

static uint8_t	third_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int16_t *loc)
{
	int16_t	tmp;

	tmp = 0;
	if (((acb >> 2) & 3) == REG_CODE)
	{
		tmp = cyc->mem[mem(pc->i + 3 + acb_arg_1((acb >> 4) & 3))].byte;
		if (reg(tmp))
			tmp = pc->r[tmp];
	}
	else if (((acb >> 2) & 3) == DIR_CODE || ((acb >> 2) & 3) == IND_CODE)
		cw_memren(&tmp,
					&cyc->mem[mem(pc->i + 3 + acb_arg_1((acb >> 4) & 3))],
					IND_SIZE);
	else
	{
		pc->i = mem(pc->i + acb_len(acb, 1));
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
	acb = cyc->mem[mem(pc->i + 1)].byte;
	if (!first_check(cyc, pc, acb))
		return ;
	if (!second_check(cyc, pc, acb, &loc))
		return ;
	if (!third_check(cyc, pc, acb, &loc))
		return ;
	cw_memwen(&cyc->mem[mem(pc->i + idx((int16_t)loc))],
				&pc->r[cyc->mem[mem(pc->i + 2)].byte], REG_SIZE, pc->r[0]);
	pc->i = mem(pc->i + acb_len(acb, 1));
}
