/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:24:55 by jochang           #+#    #+#             */
/*   Updated: 2019/02/12 22:24:56 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splash_screen.h"

static void	p1(t_splash s, int ch)
{
	print_name(s, ch, 1, "▄████████");
	print_name(s, ch, 12, "▄██████▄");
	print_name(s, ch, 24, "▄████████");
	print_name(s, ch, 38, "▄████████");
	print_name(s, ch, 49, "▄█");
	print_name(s, ch, 56, "█▄");
	print_name(s, ch, 63, "▄████████");
	print_name(s, ch, 76, "▄████████");
	ch++;
	print_name(s, ch, 0, "███");
	print_name(s, ch, 7, "███");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 24, "███");
	print_name(s, ch, 31, "███");
	print_name(s, ch, 37, "███");
	print_name(s, ch, 44, "███");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "███");
	print_name(s, ch, 75, "███");
	print_name(s, ch, 82, "███");
}

static void	p2(t_splash s, int ch)
{
	print_name(s, ch, 0, "███");
	print_name(s, ch, 7, "█▀");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 24, "███");
	print_name(s, ch, 31, "███");
	print_name(s, ch, 37, "███");
	print_name(s, ch, 44, "█▀");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "███");
	print_name(s, ch, 75, "███");
	print_name(s, ch, 82, "███");
	ch++;
	print_name(s, ch, 0, "███");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 23, "▄███▄▄▄▄██▀");
	print_name(s, ch, 36, "▄███▄▄▄");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "███");
	print_name(s, ch, 74, "▄███▄▄▄▄██▀");
}

static void	p3(t_splash s, int ch)
{
	print_name(s, ch, 0, "███");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 22, "▀▀███▀▀▀▀▀");
	print_name(s, ch, 35, "▀▀███▀▀▀");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 60, "▀███████████");
	print_name(s, ch, 73, "▀▀███▀▀▀▀▀");
	ch++;
	print_name(s, ch, 0, "███");
	print_name(s, ch, 7, "█▄");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 22, "▀███████████");
	print_name(s, ch, 37, "███");
	print_name(s, ch, 44, "█▄");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "███");
	print_name(s, ch, 73, "▀███████████");
}

static void	p4(t_splash s, int ch)
{
	print_name(s, ch, 0, "███");
	print_name(s, ch, 7, "███");
	print_name(s, ch, 11, "███");
	print_name(s, ch, 18, "███");
	print_name(s, ch, 24, "███");
	print_name(s, ch, 31, "███");
	print_name(s, ch, 37, "███");
	print_name(s, ch, 44, "███");
	print_name(s, ch, 48, "███");
	print_name(s, ch, 52, "▄█▄");
	print_name(s, ch, 56, "███");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "███");
	print_name(s, ch, 75, "███");
	print_name(s, ch, 82, "███");
	ch++;
	print_name(s, ch, 0, "████████▀");
	print_name(s, ch, 12, "▀██████▀");
	print_name(s, ch, 24, "███");
	print_name(s, ch, 31, "███");
	print_name(s, ch, 37, "██████████");
	print_name(s, ch, 49, "▀███▀███▀");
	print_name(s, ch, 62, "███");
	print_name(s, ch, 69, "█▀");
	print_name(s, ch, 75, "███");
}

void		splash_name(t_splash s)
{
	int	ch;

	ch = -5;
	wattron(s.win, COLOR_PAIR(1));
	p1(s, ch);
	ch += 2;
	p2(s, ch);
	ch += 2;
	p3(s, ch);
	ch += 2;
	p4(s, ch);
	ch++;
	print_name(s, ch, 82, "███");
	ch++;
	print_name(s, ch, 24, "███");
	print_name(s, ch, 31, "███");
	print_name(s, ch, 75, "███");
	print_name(s, ch, 82, "███");
	wattroff(s.win, COLOR_PAIR(1));
}
