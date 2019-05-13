/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_scan_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 19:46:50 by smonroe           #+#    #+#             */
/*   Updated: 2019/02/18 01:41:22 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	assign_tmp(t_pc *tmp)
{
	tmp->i = MEM(tmp->i + 1);
	tmp->wait = -1;
}

static void	set_cycle(t_cyc *cyc, t_pc *tmp)
{
	t_mem	front[REG_SIZE];
	t_mem	back[REG_SIZE];

	cw_memcp(front, &cyc->mem[0], REG_SIZE);
	cw_memcp(back, &cyc->mem[MEM_SIZE], REG_SIZE);
	g_op_fn[cyc->mem[tmp->i].byte](cyc, tmp);
	if (ft_memcmp(front, &cyc->mem[0], sizeof(front)))
		cw_memcp(&cyc->mem[MEM_SIZE], &cyc->mem[0], REG_SIZE);
	if (ft_memcmp(back, &cyc->mem[MEM_SIZE], sizeof(back)))
		cw_memcp(&cyc->mem[0], &cyc->mem[MEM_SIZE], REG_SIZE);
	tmp->wait = REG(cyc->mem[tmp->i].byte) ?
				WAIT_MOD(cyc->mem[tmp->i].byte) : -1;
}

void		pc_scan_op(t_cyc *cyc, t_pc *pc)
{
	t_pc	*tmp;

	tmp = pc;
	while (tmp)
	{
		tmp->wait--;
		tmp->i %= MEM_SIZE;
		if (!REG(cyc->mem[tmp->i].byte))
			assign_tmp(tmp);
		else if (REG(cyc->mem[tmp->i].byte) && !tmp->wait)
			set_cycle(cyc, tmp);
		if (tmp->wait < 0 && REG(cyc->mem[tmp->i].byte))
			tmp->wait = WAIT_MOD(cyc->mem[tmp->i].byte);
		cyc->mem[tmp->i].active = (cyc->mem[tmp->i].active == 0) ?
									1 : cyc->mem[tmp->i].active;
		tmp = tmp->next;
	}
}
