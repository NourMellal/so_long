/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:47:48 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/22 16:41:03 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*destalloc(char *str);
char	*ft_strcat(char *dest, char *src);
int		charsearch(char *buffer, char c);
char	*return_and_free(size_t len, char *buffer, char *str);
char	*readline(int fd, char *buffer, ssize_t len);
char	*process_line(char *buffer);
char	*go_to_next_line(char *buffer);
char	*get_next_line(int fd);

/* parsing */

typedef	struct s_player
{
	int	x;
	int y;
}			t_player;

typedef	struct s_pars
{
	int line_count;
	char *filecontent;
	char **map_str;
}				t_pars;

typedef struct s_data
{
	t_player player;
	t_pars	pars;
	int	fd;
	int players;
	int	coins;
	int exits;
}		t_data;

void	define_data(t_data *data);
int		check_path(char *str);
void	start_parsing(char *path, t_data *data);
void	check_if_valid_map(t_data *data);
void	check_for_err(int ac, char **av);
void	print_error_file(void);
void	print_err(char *err_type, t_data *data);
int		count_strs(char **strs);
int		check_line(t_data *data, char *s);
void	get_line(t_data *data);
void	collect_data(t_data	*data, char byte);
void	check_data(t_data *data);
void	last_and_first_line(char *str, t_data *data);
void	inner_lines(char *str, t_data *data);
void	check_edges(t_data *data);
void	find_player_pos(t_data *data);

#endif
