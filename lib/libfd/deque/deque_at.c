/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:37:55 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 20:40:18 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

t_node	*deque_at(t_deque *deque, int index)
{
	int		i;
	t_node	*node;

	if (index >= deque->size)
		return (NULL);
	i = -1;
	node = deque->begin;
	while (++i < index)
		node = node->next;
	return (node);
}
