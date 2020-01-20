/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:59 by jochang           #+#    #+#             */
/*   Updated: 2020/01/18 14:44:59 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_cyc *cyc, t_pc *pc)
{
	int32_t tmp_pnum;

	cw_memren(&tmp_pnum, &cyc->mem[mem(pc->i + 1)], REG_SIZE);
	if ((tmp_pnum > 0 ? tmp_pnum : -tmp_pnum) <= cyc->num_champs)
		cyc->last = tmp_pnum;
	else
		tmp_pnum = 1;
	if (-tmp_pnum <= MAX_PLAYERS && tmp_pnum < 0)
	{
		cw_memren(&cyc->last, &cyc->mem[mem(pc->i + 1)], REG_SIZE);
		cyc->last_live[-tmp_pnum - 1] = cyc->cycle;
		cyc->pcount[-tmp_pnum - 1]++;
	}
	pc->alive++;
	pc->i = mem(pc->i + 5);
	if (-tmp_pnum == pc->r[0])
	{
		cyc->mem[mem(pc->i - 5)].active = 2;
		cyc->mem[mem(pc->i - 5)].timer = FLASH_LEN << 1;
	}
}
