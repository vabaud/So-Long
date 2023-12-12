/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:18:59 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/24 15:52:08 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t cout)
{
	char	*block;
	int		i;

	block = ptr;
	i = 0;
	while (cout)
	{
		block[i] = (unsigned char)val;
		i++;
		cout--;
	}
	return (block);
}
