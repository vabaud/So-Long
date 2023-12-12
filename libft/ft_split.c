/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:58:53 by tom               #+#    #+#             */
/*   Updated: 2023/10/25 19:25:44 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	if (s[0] != c && s[0])
		co++;
	i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i - 1] == c && s[i] != '\0')
			co++;
		if (s[i])
			i++;
	}
	return (co);
}

static char	**mal1er(char **dest, const char *s, char c)
{
	int	i;
	int	co;
	int	j;

	j = 0;
	i = 0;
	co = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			co++;
			i++;
			if (s[i] == c || !s[i])
			{
				dest[j] = malloc(sizeof(char) * (co + 1));
				co = 0;
				j++;
			}
		}
	}
	dest[j] = NULL;
	return (dest);
}

static char	**comp(char **dest, const char *s, char c)
{
	int	i;
	int	co;
	int	j;

	j = 0;
	i = 0;
	co = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			dest[j][co] = s[i];
			co++;
			i++;
			if (s[i] == c || !s[i])
			{
				dest[j][co] = '\0';
				co = 0;
				j++;
			}
		}
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (s == NULL || s[0] == '\0')
	{
		dest = malloc(sizeof(char *) * 1);
		dest[0] = NULL;
		return (dest);
	}
	dest = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dest)
		return (NULL);
	dest = mal1er(dest, s, c);
	dest = comp(dest, s, c);
	return (dest);
}
