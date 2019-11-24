/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:07:40 by eestela           #+#    #+#             */
/*   Updated: 2019/11/23 20:36:26 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char a)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	int				i;
	unsigned int	start;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	i = -1;
	len = ft_strlen(s1);
	while (ft_isset(set, s1[++i]) == 1)
	{
		len--;
		start++;
	}
	i = ft_strlen(s1);
	while (ft_isset(set, s1[--i]) == 1 && len > 0)
		len--;
	return (ft_substr(s1, start, len));
}
