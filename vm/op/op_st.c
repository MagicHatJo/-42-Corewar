/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:00:46 by jochang           #+#    #+#             */
/*   Updated: 2019/05/08 22:02:19 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	reg_check(t_pc *pc, uint8_t acb)
{
	if (((acb >> 6) & 3) == REG_CODE)
		return (1);
	pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	return (0);
}

void			op_st(t_cyc *c, t_pc *pc)
{
	int16_t		loc;
	uint8_t		acb;

	acb = c->mem[MEM(pc->i + 1)].byte;
	RETURN_CHECK(!reg_check(pc, acb));
	if (((acb >> 4) & 3) == REG_CODE)
	{
		pc->r[c->mem[MEM(pc->i + 3)].byte] = pc->r[c->mem[MEM(pc->i + 2)].byte];
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	}
	else if (((acb >> 4) & 3) == IND_CODE || ((acb >> 4) & 3) == DIR_CODE)
	{
		cw_memren(&loc, &c->mem[MEM(pc->i + 3)], IND_SIZE);
		cw_memwen(&c->mem[MEM(pc->i + IDX(loc))],
					&pc->r[c->mem[MEM(pc->i + 2)].byte], REG_SIZE, pc->r[0]);
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
	}
	else
		pc->i = MEM(pc->i + acb_len((acb >> 2), 0));
}
