/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:47:48 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/20 19:15:03 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

// for mac
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ON_DESTROY 17

// for linux
// # define KEY_ESC 65307
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define ON_DESTROY 33

char			*destalloc(char *str);
char			*ft_strcat(char *dest, char *src);
int				charsearch(char *buffer, char c);
char			*return_and_free(size_t len, char *buffer, char *str);
char			*readline(int fd, char *buffer, ssize_t len);
char			*process_line(char *buffer);
char			*go_to_next_line(char *buffer);
char			*get_next_line(int fd);

/* parsing */

typedef struct s_player
{
	void		**texture;
	void		*up[4];
	void		*down[4];
	void		*left[4];
	void		*right[4];
	int			current_frame;
	int			x;
	int			y;
}				t_player;

typedef struct s_pars
{
	int			width;
	int			height;
	long		line_count;
	char		*filecontent;
	char		**map_str;
	char		**map_copy;
	char		**map_copy2;
}				t_pars;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*wall;
	void		*exit;
	void		*coin;
	void		*floor;
	void		*moves;
	int			flag;
}				t_game;

typedef struct s_data
{
	t_player	player;
	t_pars		pars;
	t_game		game;
	int			movements;
	int			frames_elapsed;
	int			fd;
	int			players;
	int			coins;
	int			collected_coins;
	int			exits;
}				t_data;

void			define_data(t_data *data);
int				check_path(char *str);
void			start_parsing(char *path, t_data *data);
void			check_if_valid_map(t_data *data);
void			check_for_err(int ac, char **av);
void			print_error_file(void);
void			print_err(char *err_type, t_data *data, int print_err);
int				count_strs(char **strs);
void			check_line(t_data *data, char *s, long line);
void			get_line(t_data *data);
void			collect_data(t_data *data, char byte);
void			check_data(t_data *data);
void			last_and_first_line(char *str, t_data *data);
void			inner_lines(char *str, t_data *data);
void			check_edges(t_data *data);
void			find_player_pos(t_data *data);
void			flood_fill_coin(t_data *data, char **map, int x, int y);
void			check_path_for_player(t_data *data);
int				flood_fill_exit(t_data *data, int x, int y);
void			free_map_copy(t_data *data);
void			start_game(t_data *data);
void			define_textures(t_data *data);
int				draw_frame(t_data *data);
int				key_hook(int key, t_data *data);
void			key_hook2(int key, t_data *data);
void			define_textures2(t_data *data);
void			draw_map(t_data *data);
void			w_key(t_data *data);
void			a_key(t_data *data);
void			s_key(t_data *data);
void			d_key(t_data *data);
void			define_textures3(t_data *data);
void			check_player_postion(t_data *data);
void			free_2d_maps(char **arr);
int				count_line(char *str);

#endif
