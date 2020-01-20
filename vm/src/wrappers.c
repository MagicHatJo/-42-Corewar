/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 21:00:29 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 15:28:20 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint32_t	mem(int32_t x)
{
	return (((x) < 0) ? (MEM_SIZE + ((x) % MEM_SIZE)) : ((x) % MEM_SIZE));
}

uint32_t	idx(int32_t x)
{
	return (x % IDX_MOD);
}

int			acb_arg(int x)
{
	return ((int[]){0, 1, 2, 4}[x]);
}

int			acb_arg_1(int x)
{
	return ((int[]){0, 1, 2, 2}[x]);
}

int			reg(int x)
{
	return ((x) > 0 && (x) <= REG_NUMBER);
}
