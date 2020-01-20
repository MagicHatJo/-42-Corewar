/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:37:16 by jochang           #+#    #+#             */
/*   Updated: 2019/09/29 19:37:17 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFD_H
# define LIBFD_H

# include <stdbool.h>
# include <stdlib.h>

/*
** Generic Structs
*/
typedef struct	s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

/*
** Deque
*/
typedef struct	s_deque
{
	struct s_node	*begin;
	struct s_node	*end;
	int				size;
}				t_deque;

/*
** Constructor
*/
t_deque			*deque_init(void);

/*
** Iterators
** Begin : Return iterator to beginning
** End   : Return iterator to end
*/
t_node			*deque_begin(t_deque *deque);
t_node			*deque_end(t_deque *deque);

/*
** Capacity
** Size  : Return size
** Empty : Test whether container is empty
*/
int				deque_size(t_deque *deque);
bool			deque_empty(t_deque *deque);

/*
** Access
** At    : Access element at index
** Front : Access first element
** Back  : Access last element
*/
t_node			*deque_at(t_deque *deque, int index);
t_node			*deque_front(t_deque *deque);
t_node			*deque_back(t_deque *deque);

/*
** Modifiers
** Push Back  : Add element to end of deque
** Push Front : Add element to beginning of deque
** Pop Back   : Remove element from end of deque and return its contents
** Pop Front  : Remove element from front of deque and return its contents
*/
void			deque_push_back(t_deque *deque, void *content);
void			deque_push_front(t_deque *deque, void *content);
void			*deque_pop_back(t_deque *deque);
void			*deque_pop_front(t_deque *deque);

/*
** Future modifiers to implement
** Insert elements (public member function )
** Erase elements (public member function )
** Swap content (public member function )
** Clear content (public member function )
*/

/*
** Queue
*/
typedef struct	s_queue
{
	struct s_node	*front;
	struct s_node	*back;
	int				size;
}				t_queue;

t_queue			*queue_init(void);
bool			queue_empty(t_queue *queue);
int				queue_size(t_queue *queue);
void			*queue_front(t_queue *queue);
void			*queue_back(t_queue *queue);
void			queue_push(t_queue *queue, void *content);
void			*queue_pop(t_queue *queue);

#endif
