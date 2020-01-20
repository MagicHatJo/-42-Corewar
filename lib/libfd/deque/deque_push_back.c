/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:00:31 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 21:03:23 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

void	deque_push_back(t_deque *deque, void *content)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return ;
	new->content = content;
	new->prev = deque->end;
	new->next = deque->begin;
	if (!deque->begin)
		deque->begin = new;
	else
		deque->end->next = new;
	deque->end = new;
	deque->begin->prev = deque->end;
	deque->size++;
}
