/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:01:15 by jochang           #+#    #+#             */
/*   Updated: 2019/02/21 17:43:53 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_cyc *cyc, t_pc *pc)
{
	int16_t addr;

	if (pc->carry)
	{
		cw_memren(&addr, &cyc->mem[MEM(pc->i + 1)], IND_SIZE);
		pc->i = MEM(pc->i + IDX(addr));
	}
	else
		pc->i = MEM(pc->i + 3);
}
