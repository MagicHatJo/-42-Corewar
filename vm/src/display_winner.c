/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:28:21 by jochang           #+#    #+#             */
/*   Updated: 2020/01/18 14:48:09 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_winner(t_head *head, int winner)
{
	if (winner <= -1 && winner >= -MAX_PLAYERS)
		ft_printf("Fighter #%d, \"%s\", has won !\n",
					-winner,
					head[-winner - 1].name);
	else
		ft_printf("There has been a tie!\n");
}
