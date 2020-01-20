/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:59:20 by jochang           #+#    #+#             */
/*   Updated: 2019/05/08 22:02:15 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_cyc *cyc, t_pc *pc)
{
	int16_t	addr;
	t_pc	*new;

	cw_memren(&addr, &cyc->mem[mem(pc->i + 1)], IND_SIZE);
	new = pc_new(-(pc->r[0]), mem(pc->i + idx(addr)),
				cyc->mem[mem(pc->i + idx(addr))].byte);
	ft_memcpy(new->r, pc->r, sizeof(new->r));
	new->carry = pc->carry;
	new->alive = pc->alive;
	pc_app(&g_head, new);
	pc->i = mem(pc->i + 3);
	cyc->pc_info[pc->r[0]]++;
}
