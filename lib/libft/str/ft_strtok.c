/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:36:42 by jochang           #+#    #+#             */
/*   Updated: 2019/06/03 07:36:43 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	uint8_t	hash[256];
	int		i;

	if (!str)
		return (NULL);
	if (!delim)
		return (ft_strdup(str));
	ft_bzero(&hash, 256);
	i = -1;
	while (delim[++i])
		hash[(int)delim[i]] = 1;
	i = -1;
	while (str[++i])
	{
		if (hash[(int)str[i]])
			return (ft_strndup(str, i));
	}
	return (ft_strdup(str));
}
