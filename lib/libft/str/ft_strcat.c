/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:27:26 by jochang           #+#    #+#             */
/*   Updated: 2018/04/20 00:50:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (0);
	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k])
		s1[i++] = s2[k++];
	s1[i] = '\0';
	return (s1);
}
