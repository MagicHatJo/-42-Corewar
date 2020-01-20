/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nofile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:29:19 by jochang           #+#    #+#             */
/*   Updated: 2020/01/18 14:53:09 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"

void	err_nofile(char *prog, int n)
{
	if (n >= 2)
		return ;
	if (ft_strequ(prog, "asm"))
	{
		ft_printf("Usage:\t./asm [file].s\n");
		ft_printf("Compiles champion .s file to .cor binary file.\n");
		ft_printf("No successive arguments are taken.\n");
	}
	else if (ft_strequ(prog, "cw"))
	{
		ft_printf("Usage: ./corewar [-n -d] [-w N] [champion].cor\n");
		ft_printf("\t-n: Ncurses Visualizer\n");
		ft_printf("\t-w [cycles per second]: Set Ncurses Visualizer speed\n");
		ft_printf("\t-d: Set Debug Mode for Ncurses Visualizer\n");
		ft_printf("\t\tPress key to advance 1 cycle, hold");
		ft_printf(" key to run continously\n");
		ft_printf("-d and -w will only work if -n flag is present.\n\n");
		ft_printf("Corewar takes 1 - 4 .cor files and runs them in the ");
		ft_printf("Virtual Machine.\nWritten by jochang, jtashako, ");
		ft_printf("and smonroe.\n42 Silicon Valley\n");
	}
	exit(1);
}
