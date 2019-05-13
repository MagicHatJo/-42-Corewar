/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:21:57 by jochang           #+#    #+#             */
/*   Updated: 2019/03/12 19:21:58 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	player_intros(t_head *head, int n)
{
	int	i;

	i = -1;
	ft_printf("Introducing the fighters...\n");
	while (++i < n)
		ft_printf("Fighter #%d: %s (\"%s\"), at %d bytes long!\n",
		-head[i].pnum, head[i].name, head[i].comment, head[i].size);
}

static void	corewar(int ac, char **av, t_flag *flags)
{
	int		n;
	t_head	*head;
	t_mem	*mem;
	t_cyc	*cyc;

	if (!(head = ft_memalloc(sizeof(t_head) * MAX_PLAYERS)))
		err_malloc("main");
	if (file_handler(ac, av, head))
	{
		n = player_count(head);
		mem = init_mem(head, n);
		init_pc(mem, head, n);
		cyc = init_cyc(mem, flags, n);
		player_intros(head, n);
		vm(cyc, head, flags);
		display_winner(head, cyc->last);
		free(mem);
		pc_free(g_head);
		free(cyc);
	}
	free(head);
}

int			main(int ac, char **av)
{
	t_flag	flags;

	flags = ft_setopt(ac, av);
	if (g_optind >= ac)
		err_nofile("cw", 1);
	corewar(ac, av, &flags);
	return (0);
}
