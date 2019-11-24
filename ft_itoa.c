/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 02:12:55 by eestela           #+#    #+#             */
/*   Updated: 2019/11/20 19:14:33 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sizenum(unsigned int n)
{
	if (n > 9)
		return (1 + ft_sizenum(n / 10));
	else
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char			*tab;
	int				len;
	unsigned int	m;
	int				plus;

	plus = 1;
	if (n < 0)
	{
		m = -n;
		plus++;
	}
	else
		m = n;
	len = ft_sizenum(m) + plus - 1;
	if (!(tab = malloc((len + 1) * sizeof(char))))
		return (NULL);
	tab[len] = '\0';
	while (--len >= 0)
	{
		tab[len] = (m % 10) + '0';
		m = m / 10;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
