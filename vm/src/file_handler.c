/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:00:02 by jochang           #+#    #+#             */
/*   Updated: 2019/03/13 14:00:05 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	parse_file(int fd, t_head *head, int i)
{
	char	buf[COMMENT_LENGTH];
	int		ret;

	ret = read(fd, buf, 4);
	ft_memrcpy(&ret, buf, 4);
	if (ret != COREWAR_EXEC_MAGIC)
		return (0);
	ret = read(fd, buf, PROG_NAME_LENGTH);
	ft_memcpy(head->name, buf, PROG_NAME_LENGTH);
	ret = read(fd, buf, 8);
	ft_memrcpy(&head->size, &buf[4], 4);
	ret = read(fd, buf, COMMENT_LENGTH - 4);
	ft_memcpy(head->comment, buf, COMMENT_LENGTH - 4);
	ret = read(fd, buf, head->size);
	ft_memcpy(head->code, buf, head->size);
	head->pnum = -(i + 1);
	return (1);
}

int			file_handler(int ac, char **av, t_head *head)
{
	int		i;
	int		fd;

	i = 0;
	while (g_optind < ac && i < MAX_PLAYERS)
	{
		if ((fd = open(av[g_optind], O_RDONLY)) == -1)
			return (err_invfile(av[g_optind]));
		if (!(parse_file(fd, &head[i], i)))
		{
			close(fd);
			return (err_invfile(av[g_optind]));
		}
		close(fd);
		g_optind++;
		i++;
	}
	return (1);
}
