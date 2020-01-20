/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:14:30 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 20:14:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	*queue_pop(t_queue *queue)
{
	t_node	*node;
	void	*c;

	if (!queue->front)
		return (NULL);
	node = queue->front;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->back = NULL;
	queue->size--;
	node->next = NULL;
	c = node->content;
	free(node);
	return (c);
}
