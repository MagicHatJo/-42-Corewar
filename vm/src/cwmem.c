/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 02:04:10 by jochang           #+#    #+#             */
/*   Updated: 2019/03/21 02:04:11 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline void	cw_memcp(t_mem *dst, t_mem *src, size_t n)
{
	int i;

	i = -1;
	while ((size_t)(++i) < n)
		dst[i] = src[i];
}

void		cw_memwen(t_mem *mem, void *src, size_t n, int pnum)
{
	uint8_t	*s;
	int		i;

	s = src;
	i = -1;
	while ((size_t)(++i) < n)
	{
		mem[i].byte = s[n - i - 1];
		mem[i].pnum = pnum;
		mem[i].timer = FLASH_LEN;
	}
}

void		cw_memren(void *dst, t_mem *mem, size_t n)
{
	uint8_t	*d;
	int		i;

	d = dst;
	i = -1;
	while ((size_t)(++i) < n)
		d[i] = mem[n - i - 1].byte;
}
