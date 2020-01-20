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

#ifndef GUI_H
# define GUI_H

# include <curses.h>
# include <locale.h>
# include "corewar.h"

# define MEMWIN_HEIGHT			68
# define MEMWIN_WIDTH			197
# define INFOWIN_WIDTH			58
# define COLOR_GRAY				242
# define WINDOWS_OFFSET_LEFT	3
# define INIT_BRACKETS	"[                                                  ]"
# define INIT_DASHES	"--------------------------------------------------"

typedef struct	s_ncrs
{
	WINDOW		*memwin;
	WINDOW		*infowin;
	uint8_t		paused;
	uint8_t		init_x;
	uint8_t		init_y;
}				t_ncrs;

t_ncrs			*init_gui(t_cyc *c, t_head *h, t_flag *f);
void			update_gui(t_ncrs *n, t_cyc *c, t_head *h, t_flag *f);
void			update_memblock(t_ncrs *n, t_cyc *c, t_flag *f);
void			update_infoblock(t_ncrs *n, t_cyc *c, t_head *h, t_flag *f);
void			print_breakdown(t_ncrs *n, t_cyc *c, uint8_t w);
void			splash_screen(void);
void			delete_gui(t_ncrs *n);
int				total_processes(t_cyc *c);
void			print_info(t_ncrs *ncrs, char *info);
void			print_info_n(t_ncrs *ncrs, char *info, int d);

#endif
