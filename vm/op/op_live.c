/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:59 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:42:55 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_cyc *cyc, t_pc *pc)
{
	int32_t tmp_pnum;

	cw_memren(&tmp_pnum, &cyc->mem[MEM(pc->i + 1)], REG_SIZE);
	if (ABS(tmp_pnum) <= cyc->num_champs)
		cyc->last = tmp_pnum;
	else
		tmp_pnum = 1;
	cw_memren(&cyc->last, &cyc->mem[MEM(pc->i + 1)], REG_SIZE);
	if (-tmp_pnum <= MAX_PLAYERS && tmp_pnum < 0)
	{
		cyc->last_live[-tmp_pnum - 1] = cyc->cycle;
		cyc->pcount[-tmp_pnum - 1]++;
	}
	pc->alive++;
	pc->i = MEM(pc->i + 5);
	if (-tmp_pnum == pc->r[0])
	{
		cyc->mem[MEM(pc->i - 5)].active = 2;
		cyc->mem[MEM(pc->i - 5)].timer = FLASH_LEN << 1;
	}
}
