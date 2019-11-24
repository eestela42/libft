/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:07:41 by eestela           #+#    #+#             */
/*   Updated: 2019/11/07 23:37:37 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pointer;
	char *check;

	check = (char *)s;
	pointer = NULL;
	while (*check)
	{
		if (*check == c)
			pointer = check;
		check++;
	}
	if (c == '\0')
		return (check);
	return (pointer);
}
