/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:18:47 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/24 03:17:41 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tadest;
	unsigned char	*tasrc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tadest = (unsigned char *)dest;
	tasrc = (unsigned char *)src;
	while (i < n)
	{
		tadest[i] = tasrc[i];
		i++;
	}
	return (dest);
}
