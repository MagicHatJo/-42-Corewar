/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acb_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 19:43:25 by smonroe           #+#    #+#             */
/*   Updated: 2019/02/13 01:35:47 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline uint16_t	acb_len(uint8_t acb, bool last_field)
{
	static const uint16_t	l[] = {0, 1, 4, 2};
	static const uint16_t	l2[] = {0, 1, 2, 2};
	uint16_t				len;

	if (!last_field)
		len = l[acb >> 6] + l[(acb >> 4) & 3] + l[(acb >> 2) & 3] + 2;
	else
		len = l2[acb >> 6] + l2[(acb >> 4) & 3] + l2[(acb >> 2) & 3] + 2;
	return (len);
}
