/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:33:11 by eestela           #+#    #+#             */
/*   Updated: 2019/11/20 19:55:16 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (!(tab = (void*)malloc(sizeof(void) * count * size)))
		return (NULL);
	if (!(tab = ft_memset(tab, 0, count * size)))
		return (NULL);
	return (tab);
}
