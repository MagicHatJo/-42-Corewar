/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:04:20 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 20:04:21 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	*queue_front(t_queue *queue)
{
	if (!queue->front)
		return (NULL);
	return (queue->front->content);
}
