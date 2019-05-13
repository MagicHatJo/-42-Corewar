/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:16:51 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 23:16:51 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		player_count(t_head *head)
{
	int	n;

	n = 0;
	while (n < MAX_PLAYERS && head[n].pnum)
		n++;
	return (n);
}