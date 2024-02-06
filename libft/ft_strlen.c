/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:19:52 by tbihoues          #+#    #+#             */
/*   Updated: 2024/02/05 19:01:46 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
