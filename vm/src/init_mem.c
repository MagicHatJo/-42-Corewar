/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:45:19 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 17:45:20 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_mem		*init_mem(t_head *head, int n)
{
	t_mem	*mem;
	int		i;
	int		k;
	int		offset;

	mem = ft_memalloc(sizeof(t_mem) * (MEM_SIZE + 4));
	i = -1;
	while (++i < n)
	{
		k = -1;
		offset = ((MEM_SIZE / n) * i);
		while (++k < head[i].size)
		{
			mem[k + offset].byte = head[i].code[k];
			mem[k + offset].pnum = -(head[i].pnum);
		}
		mem[offset].active = 1;
	}
	return (mem);
}
