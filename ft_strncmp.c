/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:46:40 by eestela           #+#    #+#             */
/*   Updated: 2019/11/28 16:06:56 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s11;
	unsigned char	*s22;

	if (n == 0)
		return (0);
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	i = 0;
	while (s11[i] && s22[i] && i < n)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	if ((s11[i] || s22[i]) && (i < n))
		return (s11[i] - s22[i]);
	return (0);
}
