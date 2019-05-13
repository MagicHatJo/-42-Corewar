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
	pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	return (0);
}

static uint8_t	dir_check(t_cyc *cyc, t_pc *pc, uint8_t acb)
{
	uint8_t	reg;

	if (((acb >> 6) & 3) != DIR_CODE)
		return (0);
	reg = cyc->mem[MEM(pc->i + 6)].byte;
	if (REG(reg))
	{
		cw_memren(&pc->r[reg], &cyc->mem[MEM(pc->i + 2)], REG_SIZE);
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
		pc->carry = (pc->r[reg]) ? 0 : 1;
	}
	else
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	return (1);
}

static uint8_t	ind_check(t_cyc *cyc, t_pc *pc, uint8_t acb)
{
	uint8_t	reg;
	int16_t	loc;

	if (((acb >> 6) & 3) != IND_CODE)
		return (0);
	reg = cyc->mem[MEM(pc->i + 4)].byte;
	cw_memren(&loc, &cyc->mem[MEM(pc->i + 2)], IND_SIZE);
	if (REG(reg))
	{
		cw_memren(&pc->r[reg], &cyc->mem[MEM(pc->i + IDX(loc))], REG_SIZE);
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
		pc->carry = (pc->r[reg]) ? 0 : 1;
	}
	else
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	return (1);
}

void			op_ld(t_cyc *cyc, t_pc *pc)
{
	uint8_t	acb;

	acb = cyc->mem[MEM(pc->i + 1)].byte;
	RETURN_CHECK(!reg_check(pc, acb));
	RETURN_CHECK(dir_check(cyc, pc, acb));
	RETURN_CHECK(ind_check(cyc, pc, acb));
	pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
}
