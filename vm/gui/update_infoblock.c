/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_infoblock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:18:19 by jochang           #+#    #+#             */
/*   Updated: 2020/01/18 14:02:33 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static void	update_upper(t_ncrs *ncrs, t_cyc *cycle, t_flag *flag)
{
	print_info_n(ncrs, "Cycles/second limit : %d", 1000000 / flag->w);
	ncrs->init_y += 2;
	print_info_n(ncrs, "              Cycle : %d", cycle->cycle);
	ncrs->init_y += 2;
	print_info_n(ncrs, "          Processes : %d", total_processes(cycle));
	ncrs->init_y += 2;
}

static void	update_players(t_ncrs *ncrs, t_cyc *cycle, t_head *head)
{
	int		i;

	i = -1;
	while (++i < cycle->num_champs)
	{
		print_info_n(ncrs, "Player %d :", -(i + 1));
		wattron(ncrs->infowin, COLOR_PAIR(i + 1));
		mvwprintw(ncrs->infowin, ncrs->init_y, ncrs->init_x + 12, head[i].name);
		wattroff(ncrs->infowin, COLOR_PAIR(i + 1));
		ncrs->init_y++;
		print_info_n(ncrs, "  Processes               : %d",
					cycle->pc_info[i + 1]);
		ncrs->init_y++;
		print_info_n(ncrs, "  Last live               : %d",
			cycle->last_live[i]);
		ncrs->init_y++;
		print_info_n(ncrs, "  Lives in current period : %d",
			cycle->current_live[i]);
		ncrs->init_y += 2;
	}
}

static void	update_breakdown(t_ncrs *ncrs, t_cyc *cycle)
{
	print_info(ncrs, "Live breakdown for current period :");
	ncrs->init_y++;
	print_breakdown(ncrs, cycle, 0);
	ncrs->init_y += 2;
	print_info(ncrs, "Live breakdown for last period :");
	ncrs->init_y++;
	print_breakdown(ncrs, cycle, 1);
	ncrs->init_y += 2;
}

static void	update_lower(t_ncrs *ncrs, t_cyc *c)
{
	print_info_n(ncrs, "CYCLE_TO_DIE : %-4d", c->die);
	ncrs->init_y += 2;
	print_info_n(ncrs, " CYCLE_DELTA : %d", CYCLE_DELTA);
	ncrs->init_y += 2;
	print_info_n(ncrs, "    NBR_LIVE : %d", NBR_LIVE);
	ncrs->init_y += 2;
	print_info_n(ncrs, "  MAX_CHECKS : %d", MAX_CHECKS);
}

void		update_infoblock(t_ncrs *ncrs, t_cyc *c, t_head *head, t_flag *flag)
{
	ncrs->init_x = WINDOWS_OFFSET_LEFT;
	ncrs->init_y = 2;
	wattron(ncrs->infowin, A_BOLD);
	print_info(ncrs, ncrs->paused ? "** PAUSED ** " : "** RUNNING **");
	ncrs->init_y += 2;
	update_upper(ncrs, c, flag);
	update_players(ncrs, c, head);
	update_breakdown(ncrs, c);
	update_lower(ncrs, c);
	wnoutrefresh(ncrs->infowin);
}
