/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:14 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/20 21:33:30 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
char	*destalloc(char *str);
char	*ft_strcat(char *dest, char *src);
int		charsearch(char *buffer, char c);
char	*return_and_free(size_t len, char *buffer, char *str);
char	*readline(int fd, char *buffer, ssize_t len);
char	*process_line(char *buffer);
char	*go_to_next_line(char *buffer);
char	*get_next_line(int fd);

#endif