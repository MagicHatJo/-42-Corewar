/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:40:14 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 23:40:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cyc	*init_cyc(t_mem *mem, t_flag *flags, int n)
{
	t_cyc	*cyc;
	int		i;

	cyc = ft_memalloc(sizeof(t_cyc));
	i = 0;
	while (i < n)
		cyc->pc_info[i++] = 1;
	cyc->die = CYCLE_TO_DIE;
	cyc->num_champs = n;
	cyc->mem = mem;
	if (flags->b)
		cyc->verification_bytestring = read_bytestring();
	return (cyc);
}
