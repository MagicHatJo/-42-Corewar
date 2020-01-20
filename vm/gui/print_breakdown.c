/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_breakdown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:19:10 by jochang           #+#    #+#             */
/*   Updated: 2019/02/15 16:19:12 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static void		print_dash(t_ncrs *ncrs, int offset, int i, int p)
{
	int		k;

	k = -1;
	wattron(ncrs->infowin, COLOR_PAIR(i));
	while (++k < p && offset + k <= 50)
		mvwprintw(ncrs->infowin, ncrs->init_y, ncrs->init_x + offset + k, "-");
	wattroff(ncrs->infowin, COLOR_PAIR(i));
}

static int		get_lim(t_cyc *cycle, uint8_t w)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (++i < cycle->num_champs)
		if (!w)
		{
			if (cycle->current_live[i])
				n++;
		}
		else if (cycle->prev_live[i])
			n++;
	return (50 + (n >> 1));
}

static void		init_line(t_ncrs *ncrs)
{
	wattroff(ncrs->infowin, A_BOLD);
	mvwprintw(ncrs->infowin, ncrs->init_y, ncrs->init_x + 1, INIT_DASHES);
	wattron(ncrs->infowin, A_BOLD);
}

static uint32_t	live_count(t_cyc *cyc, int i, uint8_t w)
{
	return (w ? cyc->prev_live[i] : cyc->current_live[i]);
}

void			print_breakdown(t_ncrs *ncrs, t_cyc *cycle, uint8_t w)
{
	int		i;
	int		p;
	int		lim;
	int		offset;

	i = -1;
	lim = get_lim(cycle, w);
	offset = 1;
	wattron(ncrs->infowin, COLOR_PAIR(21));
	print_info(ncrs, INIT_BRACKETS);
	init_line(ncrs);
	if (cycle->breakdown[w])
	{
		while (++i < cycle->num_champs)
		{
			if (live_count(cycle, i, w) && cycle->breakdown[w])
			{
				p = live_count(cycle, i, w) * lim / cycle->breakdown[w];
				print_dash(ncrs, offset, i + 1, p);
				offset += p;
			}
		}
	}
	wattroff(ncrs->infowin, COLOR_PAIR(21));
}
