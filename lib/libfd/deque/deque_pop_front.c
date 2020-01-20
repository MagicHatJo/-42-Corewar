/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:39:28 by jochang           #+#    #+#             */
/*   Updated: 2019/10/06 16:39:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	*deque_pop_front(t_deque *deque)
{
	void	*content;
	t_node	*new_front;

	content = NULL;
	if (!deque_size(deque))
		return (content);
	if (deque_size(deque) == 1)
	{
		new_front = NULL;
		content = deque->begin->content;
		deque->end = NULL;
	}
	else
	{
		new_front = deque->begin->next;
		content = deque->begin->content;
		deque->end->next = new_front;
		new_front->prev = deque->end;
	}
	free(deque->begin);
	deque->begin = new_front;
	deque->size--;
	return (content);
}
