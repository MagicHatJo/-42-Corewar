/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 03:22:13 by jochang           #+#    #+#             */
/*   Updated: 2019/02/09 20:20:34 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	print_info(t_ncrs *ncrs, char *info)
{
	mvwprintw(ncrs->infowin, ncrs->init_y, ncrs->init_x, info);
}

void	print_info_n(t_ncrs *ncrs, char *info, int d)
{
	mvwprintw(ncrs->infowin, ncrs->init_y, ncrs->init_x, info, d);
}
