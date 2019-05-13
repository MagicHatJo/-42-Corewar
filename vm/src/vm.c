/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 00:09:14 by jochang           #+#    #+#             */
/*   Updated: 2019/03/14 00:09:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "gui.h"

static void		set_delay(uint32_t w)
{
	static clock_t	prev;
	clock_t			now;
	clock_t			diff;

	now = clock();
	diff = now - prev;
	if (diff < w)
		usleep(w - diff);
	prev = now;
}

static void		stepper(t_ncrs *ncrs, t_cyc *cyc, t_head *head, t_flag *flag)
{
	int32_t	step;

	step = 0;
	while (step++ < cyc->die)
	{
		pc_scan_op(cyc, g_head);
		if (flag->n)
			update_gui(ncrs, cyc, head, flag);
		cyc->cycle++;
		if (flag->w)
			set_delay(flag->w);
		if ((uint32_t)cyc->cycle == flag->d)
		{
			if (flag->v)
				cw_dump_pcs();
			cw_dump_mem(cyc, -1, -1);
		}
		if (flag->b)
			verify_cycle_bytes(cyc, (cyc->verification_bytestring));
	}
}

static uint32_t	live_sum(uint32_t *p)
{
	uint32_t	total;
	uint32_t	i;

	total = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		total += p[i];
	return (total);
}

static uint32_t	kill_count(uint32_t kill, uint32_t total, t_cyc *cyc)
{
	kill++;
	if (total > NBR_LIVE || kill >= MAX_CHECKS)
	{
		kill = 0;
		cyc->die -= CYCLE_DELTA;
	}
	return (kill);
}

void			vm(t_cyc *cyc, t_head *head, t_flag *flags)
{
	t_ncrs		*ncrs;
	uint32_t	kill;
	uint32_t	total;

	kill = 0;
	ncrs = init_gui(cyc, head, flags);
	while (cyc->die > 0)
	{
		stepper(ncrs, cyc, head, flags);
		total = live_sum(cyc->pcount);
		pc_scan_rem(cyc, &g_head);
		kill = kill_count(kill, total, cyc);
	}
	delete_gui(ncrs);
}
