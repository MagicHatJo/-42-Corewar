/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:08:31 by jochang           #+#    #+#             */
/*   Updated: 2020/01/12 16:49:37 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	queue_push(t_queue *queue, void *content)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return ;
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	if (!queue->front)
		queue->front = new;
	else
		queue->back->next = new;
	queue->back = new;
	queue->size++;
}
