/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:20:05 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/25 18:43:10 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((n == 0 && !s1) || !s2[0])
		return ((char *)s1);
	if (!s1[i])
		return (NULL);
	while (s1[i] && i < n)
	{
		while (s1[i + j] && s1[i + j] == s2[j] && i + j < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
