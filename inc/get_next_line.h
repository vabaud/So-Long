/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:32:19 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/11 16:45:20 by tbihoues         ###   ########.fr       */
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