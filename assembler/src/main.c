/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:57:36 by jochang           #+#    #+#             */
/*   Updated: 2020/01/18 13:47:37 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("\033[33mUsage:\t\033[0m%s\n", "./asm [champion_name].s");
		ft_printf("\tCompiles champion.s files to .cor binary files.\n");
		return (0);
	}
	if (valid_extension(av[1], "s"))
		assembler(av[1]);
	else if (valid_extension(av[1], "cor"))
		ft_printf("Disassembler not implemented\n");
	else
		ft_printf("\033[31mError:\033[0m %s is not a valid file\n", av[1]);
	return (0);
}
