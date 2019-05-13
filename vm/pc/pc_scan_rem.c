/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_scan_rem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:48:09 by jochang           #+#    #+#             */
/*   Updated: 2019/02/15 16:42:46 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	pc_rem(t_pc **pc)
{
	t_pc *tmp;

	if (!pc)
		return ;
	if ((*pc)->next)
		(*pc)->next->prev = (*pc)->prev;
	if ((*pc)->prev)
		(*pc)->prev->next = (*pc)->next;
	else
		g_head = (*pc)->next;
	tmp = (*pc)->next;
	ft_bzero(*pc, sizeof(**pc));
	free(*pc);
	*pc = tmp;
}

void		pc_scan_rem(t_cyc *cyc, t_pc **pc)
{
	t_pc	*tmp;

	tmp = *pc;
	while (tmp)
	{
		if (!tmp->alive)
		{
			cyc->pc_info[tmp->r[0]]--;
			pc_rem(&tmp);
		}
		else
		{
			tmp->alive = 0;
			tmp = tmp->next;
		}
	}
}
