/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:25:31 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/11 16:43:49 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/get_next_line.h"

void	remove_until_newline(char *buffer)
{
	int	i;
	int	j;

	i = ft_strlen(buffer);
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			byte_read;

	byte_read = 1;
	line = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	if (ft_strchr(buffer, '\n') != NULL)
	{
		remove_until_newline(buffer);
		line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
	}
	while (byte_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
	}
	if (line[0] == '\0' || line == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
