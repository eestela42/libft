/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:20:40 by eestela           #+#    #+#             */
/*   Updated: 2019/12/08 18:30:09 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ele;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	ele = first;
	while (lst->next)
	{
		lst = lst->next;
		prev = ele;
		ele = ft_lstnew(f(lst->content));
		if (ele == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		prev->next = ele;
	}
	ele->next = NULL;
	return (first);
}
