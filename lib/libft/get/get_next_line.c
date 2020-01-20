/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:12:30 by jochang           #+#    #+#             */
/*   Updated: 2019/09/22 01:30:05 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*assign_save(t_list **save, int fd)
{
	t_list	*tmp;

	tmp = *save;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(save, tmp);
	return (*save);
}

static void		cleanup(t_list *ptr)
{
	char	*tmp;

	if ((tmp = ft_strchr(ptr->content, '\n')))
	{
		tmp = ft_strdup(tmp + 1);
		free(ptr->content);
		ptr->content = tmp;
	}
	else
		ft_strclr(ptr->content);
}

static int		loop(int fd, t_list *ptr)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		check;

	while ((check = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[check] = '\0';
		if (!(tmp = ft_strjoin(ptr->content, buf)))
			return (-1);
		free(ptr->content);
		ptr->content = tmp;
		if ((ft_strchr(ptr->content, '\n')))
			break ;
	}
	return (check);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				check;
	static t_list	*save;
	t_list			*ptr;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	ptr = assign_save(&save, fd);
	if ((check = loop(fd, ptr)) == -1)
		return (-1);
	if (!check && !ft_strlen(ptr->content))
	{
		ft_strclr(*line);
		return (0);
	}
	if (!(*line = ft_strnew(ft_strlen(ptr->content))))
		return (-1);
	*line = ft_strccpy(*line, ptr->content, '\n');
	cleanup(ptr);
	return (1);
}
