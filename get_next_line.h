/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:12:03 by vabaud            #+#    #+#             */
/*   Updated: 2023/12/09 19:46:40 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2, size_t len_s1,
						size_t len_s2);
char				*ft_strchr(const char *s, int c);
void				remove_until_newline(char *buffer);

#endif