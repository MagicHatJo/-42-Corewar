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
	cw_memren(&cyc->last, &cyc->mem[MEM(pc->i + 1)], REG_SIZE);
	if (-cyc->last - 1 < MAX_PLAYERS && -cyc->last - 1 >= 0)
	{
		cyc->last_live[-cyc->last - 1] = cyc->cycle;
		cyc->pcount[-cyc->last - 1]++;
	}
	pc->alive++;
	pc->i = MEM(pc->i + 5);
	if (-cyc->last == pc->r[0])
	{
		cyc->mem[MEM(pc->i - 5)].active = 2;
		cyc->mem[MEM(pc->i - 5)].timer = FLASH_LEN << 1;
	}
}
