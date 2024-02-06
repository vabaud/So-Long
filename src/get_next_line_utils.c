/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:15:08 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/05 19:03:37 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!new_str)
		return (NULL);
	i = 0;
	new_str[0] = '\0';
	while (i < len_s1)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (i);
	}
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
	{
		return (i + 1);
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
