/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:58:43 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 21:58:43 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_pc(t_mem *mem, t_head *head, int n)
{
	int		i;

	i = 0;
	g_head = pc_new(head[0].pnum, 0, mem[0].byte);
	while (++i < n)
		pc_app(&g_head,
		pc_new(head[i].pnum, MEM_SIZE / n * i, mem[MEM_SIZE / n * i].byte));
}
