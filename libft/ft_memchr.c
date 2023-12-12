/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:38:24 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/24 15:38:25 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sh;

	sh = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sh[i] == (unsigned char)c)
			return (sh + i);
		i++;
	}
	return (NULL);
}
