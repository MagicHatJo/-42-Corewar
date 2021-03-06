/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:24:55 by jochang           #+#    #+#             */
/*   Updated: 2019/02/12 22:24:56 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splash_screen.h"

void	print_name(t_splash s, int ch, int x, char *w)
{
	mvwprintw(s.win, s.rows / 2 + ch, (s.cols - 85) / 2 + x, w);
}
