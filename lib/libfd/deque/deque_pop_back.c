/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:39:28 by jochang           #+#    #+#             */
/*   Updated: 2019/10/06 16:39:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	*deque_pop_back(t_deque *deque)
{
	t_node	*new_end;
	void	*content;

	content = NULL;
	if (!deque_size(deque))
		return (content);
	if (deque_size(deque) == 1)
	{
		new_end = NULL;
		content = deque->end->content;
		deque->begin = NULL;
	}
	else
	{
		new_end = deque->end->prev;
		content = deque->end->content;
		deque->begin->prev = new_end;
		new_end->next = deque->begin;
	}
	free(deque->end);
	deque->end = new_end;
	deque->size--;
	return (content);
}
