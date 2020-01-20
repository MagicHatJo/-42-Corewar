/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:35 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:42:25 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	reg_check(t_pc *pc, uint8_t acb)
{
	if (((acb >> 4) & 3) == REG_CODE)
		return (1);
	pc->i = mem(pc->i + acb_len((acb >> 2), 0));
	return (0);
}

static uint8_t	dir_check(t_cyc *cyc, t_pc *pc, uint8_t acb)
{
	uint8_t	r;

	if (((acb >> 6) & 3) != DIR_CODE)
		return (0);
	r = cyc->mem[mem(pc->i + 6)].byte;
	if (reg(r))
	{
		cw_memren(&pc->r[r], &cyc->mem[mem(pc->i + 2)], REG_SIZE);
		pc->i = mem(pc->i + acb_len((acb >> 2), 0));
		pc->carry = (pc->r[r]) ? 0 : 1;
	}
	else
		pc->i = mem(pc->i + acb_len((acb >> 2), 0));
	return (1);
}

static uint8_t	ind_check(t_cyc *cyc, t_pc *pc, uint8_t acb)
{
	uint8_t	r;
	int16_t	loc;

	if (((acb >> 6) & 3) != IND_CODE)
		return (0);
	r = cyc->mem[mem(pc->i + 4)].byte;
	cw_memren(&loc, &cyc->mem[mem(pc->i + 2)], IND_SIZE);
	if (reg(r))
	{
		cw_memren(&pc->r[r], &cyc->mem[mem(pc->i + idx(loc))], REG_SIZE);
		pc->i = mem(pc->i + acb_len((acb >> 2), 0));
		pc->carry = (pc->r[r]) ? 0 : 1;
	}
	else
		pc->i = mem(pc->i + acb_len((acb >> 2), 0));
	return (1);
}

void			op_ld(t_cyc *cyc, t_pc *pc)
{
	uint8_t	acb;

	acb = cyc->mem[mem(pc->i + 1)].byte;
	if (!reg_check(pc, acb))
		return ;
	if (dir_check(cyc, pc, acb))
		return ;
	if (ind_check(cyc, pc, acb))
		return ;
	pc->i = mem(pc->i + acb_len((acb >> 2), 0));
}
