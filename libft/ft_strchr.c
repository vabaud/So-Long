/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:19:31 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/24 19:35:36 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str != NULL)
	{
		if (str[i] == (const char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (const char)c)
		return ((char *)str + i);
	return (NULL);
}
