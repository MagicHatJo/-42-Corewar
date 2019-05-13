/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bytestring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:10:07 by jochang           #+#    #+#             */
/*   Updated: 2019/05/12 17:10:07 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*read_bytestring(void)
{
	int			fd;
	long long	size;
	char		buf[STACK_LIMIT + 1];
	char		*fbuf;
	char		*oldbuf;

	fbuf = (char *)malloc(sizeof(char));
	fd = open(DEBUG_BYTESTRING_LOC, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unable to open %s\n", DEBUG_BYTESTRING_LOC);
		exit(1);
	}
	while ((size = read(fd, buf, STACK_LIMIT)))
	{
		buf[size] = '\0';
		oldbuf = fbuf;
		fbuf = ft_strjoin(fbuf, buf);
		free(oldbuf);
	}
	return (fbuf);
}
