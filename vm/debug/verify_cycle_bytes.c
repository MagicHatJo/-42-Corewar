/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_cycle_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:41:32 by jochang           #+#    #+#             */
/*   Updated: 2019/05/12 17:41:33 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	success_check(t_cyc *cyc, char *bytestring, int i)
{
	if ((bytestring[2 * i] == '\n') ||
		(bytestring[2 * i + 1] == '\n') ||
		cyc->cycle >= V_LIMIT)
	{
		ft_printf("Verification success: ");
		ft_printf("bytestring matches exactly with 42corewar\n");
		exit(0);
	}
}

static void	first_check(t_cyc *cyc, char *bytestring, t_loc loc, t_loc ij)
{
	char	oct;
	char	nibble;

	oct = HEX_SET[cyc->mem[ij.col].byte / 16 % 16];
	nibble = bytestring[2 * ij.row];
	if (oct != nibble)
	{
		ft_printf("Verification mismatch at: ");
		ft_printf("Cycle: %i, Row: %#04x(%i), Col: %i\n",
				cyc->cycle, loc.row * 4 * 16, loc.row, loc.col % MEM_WIDTH);
		ft_printf("byte string first nibble is %c.. mem is %c\n", nibble,
				HEX_SET[cyc->mem[ij.col].byte / 16 % 16]);
		ft_printf("\n");
		cw_dump_pcs();
		cw_dump_mem(cyc, loc.row, loc.col);
	}
}

static void	second_check(t_cyc *cyc, char *bytestring, t_loc loc, t_loc ij)
{
	char	oct;
	char	nibble;

	oct = HEX_SET[cyc->mem[ij.col].byte % 16];
	nibble = bytestring[2 * ij.row + 1];
	if (oct != nibble)
	{
		ft_printf("Verification mismatch at: ");
		ft_printf("Cycle: %i, Row: %#04x(%i), Col: %i\n",
				cyc->cycle, loc.row * 4 * 16, loc.row, loc.col % MEM_WIDTH);
		ft_printf("byte string second nibble is %c.. mem is %c\n", nibble,
				HEX_SET[cyc->mem[ij.col].byte % 16]);
		ft_printf("\n");
		cw_dump_pcs();
		cw_dump_mem(cyc, loc.row, loc.col);
	}
}

void		verify_cycle_bytes(t_cyc *cyc, char *bytestring)
{
	int			row;
	int			col;
	int			j;
	static int	i = MEM_SIZE;

	row = 0;
	col = 0;
	j = 0;
	while (row < MEM_HEIGHT)
	{
		success_check(cyc, bytestring, i);
		first_check(cyc, bytestring, (t_loc){row, col}, (t_loc){i, j});
		second_check(cyc, bytestring, (t_loc){row, col}, (t_loc){i, j});
		row += (!((col++ + 1) % MEM_WIDTH)) ? 1 : 0;
		i++;
		j++;
	}
}
