/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:23:02 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 20:23:03 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

t_deque	*deque_init(void)
{
	t_deque *q;

	if (!(q = malloc(sizeof(t_deque))))
		return (NULL);
	q->begin = NULL;
	q->end = NULL;
	q->size = 0;
	return (q);
}
