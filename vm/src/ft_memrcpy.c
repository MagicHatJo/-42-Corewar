/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:30:49 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 14:30:50 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_memrcpy(void *dst, void *src, size_t n)
{
	uint8_t		*p;
	uint8_t		*w;

	p = src + n - 1;
	w = dst;
	while (n--)
		*(w++) = *(p--);
}
