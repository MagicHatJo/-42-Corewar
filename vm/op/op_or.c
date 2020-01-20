/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:00:21 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:43:19 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	first_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *d1)
{
	int16_t	loc;

	if ((acb >> 6) == REG_CODE)
		ft_memrcpy(d1, &pc->r[cyc->mem[mem(pc->i + 2)].byte], REG_SIZE);
	else if ((acb >> 6) == IND_CODE)
	{
		cw_memren(&loc, &cyc->mem[mem(pc->i + 2)], IND_SIZE);
		cw_memren(d1, &cyc->mem[mem(pc->i + idx(loc))], REG_SIZE);
	}
	else if ((acb >> 6) == DIR_CODE)
		cw_memren(d1, &cyc->mem[mem(pc->i + 2)], DIR_SIZE);
	else
	{
		pc->i = mem(pc->i + acb_len(acb, 0));
		return (0);
	}
	return (1);
}

static uint8_t	second_check(t_cyc *cyc, t_pc *pc, uint8_t acb, int32_t *d2)
{
	int16_t	loc;

	if (((acb >> 4) & 3) == REG_CODE)
		ft_memrcpy(d2, &pc->r[cyc->mem[mem(pc->i + acb_arg(acb >> 6))].byte],
					REG_SIZE);
	else if (((acb >> 4) & 3) == IND_CODE)
	{
		cw_memren(&loc, &cyc->mem[mem(pc->i + 1 + acb_arg(acb >> 6))],
					IND_SIZE);
		cw_memren(d2, &cyc->mem[mem(pc->i + idx(loc))], REG_SIZE);
	}
	else if (((acb >> 4) & 3) == DIR_CODE)
		cw_memren(d2, &cyc->mem[mem(pc->i + 1 + acb_arg(acb >> 6))], DIR_SIZE);
	else
	{
		pc->i = mem(pc->i + acb_len(acb, 0));
		return (0);
	}
	return (1);
}

void			op_or(t_cyc *cyc, t_pc *pc)
{
	int32_t	d1;
	int32_t	d2;
	int16_t	loc;
	uint8_t	acb;

	d1 = 0;
	d2 = 0;
	acb = cyc->mem[mem(pc->i + 1)].byte;
	if (!first_check(cyc, pc, acb, &d1))
		return ;
	if (!second_check(cyc, pc, acb, &d2))
		return ;
	loc = acb_len(acb, 0);
	if (reg(cyc->mem[mem(pc->i + loc - 1)].byte))
	{
		pc->r[cyc->mem[mem(pc->i + loc - 1)].byte] = d1 | d2;
		pc->carry = (d1 | d2) ? 0 : 1;
		pc->i = mem(pc->i + loc);
	}
	else
		pc->i = mem(pc->i + acb_len(acb, 0));
}
