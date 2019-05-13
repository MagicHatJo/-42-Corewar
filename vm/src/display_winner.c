/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:28:21 by jochang           #+#    #+#             */
/*   Updated: 2019/03/17 23:28:22 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_winner(t_head *head, int winner)
{
	if (winner)
		ft_printf("Fighter #%d, \"%s\", has won !\n",
					-winner,
					head[-winner - 1].name);
	else
		ft_printf("There has been a tie!\n");
}
