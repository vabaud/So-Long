/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:19:37 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/03 20:15:39 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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