/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:51:07 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 19:51:07 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

t_queue	*queue_init(void)
{
	t_queue *q;

	if (!(q = malloc(sizeof(t_queue))))
		return (NULL);
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
	return (q);
}
