/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:43:19 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 20:43:46 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfd.h"

t_node	*deque_back(t_deque *deque)
{
	return (deque->end);
}