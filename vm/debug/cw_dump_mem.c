/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_dump_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:51:49 by jochang           #+#    #+#             */
/*   Updated: 2019/05/12 16:51:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_first(int col)
{
	ft_printf("0x%c", HEX_SET[col / 4096 % 16]);
	ft_printf("%c", HEX_SET[col / 256 % 16]);
	ft_printf("%c%c : ", HEX_SET[col / 16 % 16], HEX_SET[col % 16]);
}

static void	print_match(t_cyc *cyc, int i, int rm, int cm)
{
	if (rm || cm)
	{
		ft_printf("%c", HEX_SET[(cyc->mem[i].byte / 16) % 16]);
		ft_printf("%c", HEX_SET[cyc->mem[i].byte % 16]);
	}
	else
	{
		ft_printf("\033[93m%c", HEX_SET[(cyc->mem[i].byte / 16) % 16]);
		ft_printf("\033[93m%c", HEX_SET[cyc->mem[i].byte % 16]);
		ft_printf("\033[0m");
	}
}

void		cw_dump_mem(t_cyc *cyc, int erow, int ecol)
{
	int	first;
	int	col;
	int	row;
	int	i;

	first = 1;
	col = 0;
	row = 0;
	i = 0;
	while (row < MEM_HEIGHT)
	{
		first ? print_first(col) : ft_printf(" ");
		first = 0;
		print_match(cyc, i++, row ^ erow, col ^ ecol);
		if (!((col++ + 1) % MEM_WIDTH))
		{
			first = 1;
			row++;
			ft_printf("\n");
		}
	}
	free(cyc->mem);
	pc_free(g_head);
	free(cyc);
	exit(0);
}
