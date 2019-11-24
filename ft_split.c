/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 01:33:31 by eestela           #+#    #+#             */
/*   Updated: 2019/11/22 17:34:08 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check_count(char const *s, char c, int p, unsigned int j)
{
	int	words;
	int	i;

	if (p == 0)
	{
		i = -1;
		words = 0;
		while (s[++i])
		{
			if (s[i] != c && j == 1)
				words++;
			if (s[i] != c)
				j = 0;
			else if (s[i] == c)
				j = 1;
		}
		return (words);
	}
	else
	{
		if (s[j] == c)
			return (1);
		return (0);
	}
}

static char			**ft_freewords(int words, char **tab)
{
	int i;

	i = 0;
	while (i < words)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char			**ft_filltab(char const *s, char c, char **tab, int word)
{
	unsigned int	start;
	unsigned int	end;

	end = 0;
	while (ft_check_count(s, c, 1, end) == 1 && s[end])
		end++;
	while (s[end])
	{
		start = end;
		while (ft_check_count(s, c, 1, end) == 0 && s[end])
			end++;
		tab[word] = ft_substr(s, start, end - start);
		while (ft_check_count(s, c, 1, end) == 1 && s[end])
			end++;
		if (tab[word] == NULL)
			return (ft_freewords(word, tab));
		word++;
	}
	tab[word] = NULL;
	return (tab);
}

char				**ft_split(char const *s, char c)
{
	char			**tab;

	if (!s)
		return (NULL);
	if (!(tab = malloc((ft_check_count(s, c, 0, 1) + 1) * sizeof(char*))))
		return (NULL);
	tab = ft_filltab(s, c, tab, 0);
	return (tab);
}
