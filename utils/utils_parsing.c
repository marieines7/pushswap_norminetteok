/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloubet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:09:11 by mloubet           #+#    #+#             */
/*   Updated: 2021/12/11 15:47:11 by mloubet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	wlen(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	nwords(const char *s, char c)
{
	int		i;
	int		nwords;

	i = 0;
	nwords = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
			nwords++;
		i++;
	}
	return (nwords);
}

char	*dupword(const char *s, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * ((wlen(s, c))) + 1);
	if (!p)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**freemalloctab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		word;
	char	**tabs;
	int		i;

	i = 0;
	word = 0;
	tabs = (char **)malloc(sizeof(char *) * (nwords(s, c) + 1));
	if (!tabs)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			tabs[word] = dupword(s + i, c);
			if (!(tabs[word]))
				return (freemalloctab(tabs));
			word++;
			i = i + wlen(s + i, c);
		}
	}
	tabs[word] = NULL;
	return (tabs);
}
