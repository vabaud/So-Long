/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:14:45 by vabaud            #+#    #+#             */
/*   Updated: 2023/12/11 11:56:54 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/get_next_line.h"

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

/*int main(void)
{
	int fd = open("test.txt", O_RDONLY);  // Ouvre le fichier en lecture seule
	char *line;

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	line = get_next_line(fd);
	printf("Line read: %s\n", line);
	free(line);

	close(fd); 
		// N'oubliez pas de fermer le descripteur de fichier après utilisation

	return (0);
}*/
