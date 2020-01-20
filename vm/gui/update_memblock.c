/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_memblock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 03:28:10 by jochang           #+#    #+#             */
/*   Updated: 2019/02/13 02:04:41 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static void	select_color(t_ncrs *ncrs, t_mem *mem)
{
	int		tmp;

	tmp = 0;
	if (mem->pnum)
	{
		if (mem->active)
		{
			if (mem->active == 1)
				wattron(ncrs->memwin, A_STANDOUT);
			if (mem->active == 2)
			{
				tmp = 4;
				wattron(ncrs->memwin, A_BOLD);
				wattron(ncrs->memwin, A_STANDOUT);
			}
		}
		else if (mem->timer)
			wattron(ncrs->memwin, A_BOLD);
		wattron(ncrs->memwin, COLOR_PAIR(mem->pnum + tmp));
	}
	else
		wattron(ncrs->memwin, A_BOLD);
}

static void	deselect_color(t_ncrs *ncrs)
{
	wattrset(ncrs->memwin, COLOR_PAIR(21));
}

void		update_memblock(t_ncrs *ncrs, t_cyc *cycle, t_flag *flag)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 1;
	wattron(ncrs->memwin, COLOR_PAIR(21));
	while (++i < MEM_SIZE)
	{
		x = (i & 63) ? x + 3 : WINDOWS_OFFSET_LEFT;
		y += (i & 63) ? 0 : 1;
		select_color(ncrs, &(cycle->mem[i]));
		mvwprintw(ncrs->memwin, y, x, "%.2x", flag->h ? 0 : cycle->mem[i].byte);
		deselect_color(ncrs);
		if (ncrs->paused == 0)
		{
			if (cycle->mem[i].timer > 0)
				cycle->mem[i].timer--;
			else if (!cycle->mem[i].timer || cycle->mem[i].active == 1)
				cycle->mem[i].active = 0;
		}
	}
	wattroff(ncrs->memwin, COLOR_PAIR(21));
	wnoutrefresh(ncrs->memwin);
}
