/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_dump_pcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:06:49 by jochang           #+#    #+#             */
/*   Updated: 2019/05/12 17:06:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_dump_pcs(void)
{
	t_pc	*head;
	int		pc_num;
	int		first;
	int		i;

	pc_num = 0;
	head = g_head;
	while (head)
	{
		ft_printf("\nPC #%i : [Registers: ", pc_num++);
		first = 1;
		i = 0;
		while (i < REG_NUMBER + 1)
		{
			first ? 0 : ft_printf(", ");
			first = 0;
			ft_printf("%8x", head->r[i++]);
		}
		ft_printf("]\t[ i: %#04x(%i), carry: %i, alive: %i, wait: %i]\n",
					head->i, head->i, head->carry, head->alive, head->wait);
		head = head->next;
	}
	ft_printf("\n");
}
