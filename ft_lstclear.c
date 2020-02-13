/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:00:40 by eestela           #+#    #+#             */
/*   Updated: 2019/11/27 20:35:55 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ele;
	t_list	*next;

	ele = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (ele)
	{
		next = ele->next;
		del(ele->content);
		free(ele);
		ele = next;
	}
	*lst = NULL;
}
