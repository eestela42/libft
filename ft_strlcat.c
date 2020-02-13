/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:18:22 by eestela           #+#    #+#             */
/*   Updated: 2019/11/28 16:04:37 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	if (j >= dstsize)
		return (dstsize + (size_t)ft_strlen(src));
	i = 0;
	while (j + i < dstsize - 1 && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i + j] = 0;
	return (ft_strlen(src) + j);
}
