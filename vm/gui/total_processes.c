/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 10:27:03 by jochang           #+#    #+#             */
/*   Updated: 2019/05/12 10:27:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

int	total_processes(t_cyc *cycle)
{
	int		i;
	int		total;

	i = -1;
	total = 0;
	while (++i < cycle->num_champs)
		total += cycle->pc_info[i];
	return (total);
}
