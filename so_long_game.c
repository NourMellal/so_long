/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:08:52 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/31 11:10:16 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_postion(t_data *data)
{
	if (data->pars.map_str[data->player.y][data->player.x] == 'C')
	{
		data->pars.map_str[data->player.y][data->player.x] = '0';
		data->collected_coins++;
	}
	if (data->pars.map_str[data->player.y][data->player.x] == 'E'
		&& data->collected_coins >= data->coins)
	{
		mlx_destroy_window(data->game.mlx, data->game.win);
		free_2d_maps(data->pars.map_str);
		free(data->game.mlx);
		ft_putendl_fd("You won", 1);
		exit(0);
	}
}

int	draw_frame(t_data *data)
{
	mlx_clear_window(data->game.mlx, data->game.win);
	check_player_postion(data);
	draw_map(data);
	data->frames_elapsed++;
	if (data->frames_elapsed == 10)
	{
		data->player.current_frame = (data->player.current_frame + 1) % 4;
		data->frames_elapsed = 0;
	}
	mlx_put_image_to_window(data->game.mlx, data->game.win,
		data->player.texture[data->player.current_frame], data->player.x * 32,
		data->player.y * 32);
	return (0);
}

void	*choose_img(t_data *data, char c)
{
	if (c == '1')
		return (data->game.wall);
	else if (c == 'E')
		return (data->game.exit);
	else if (c == 'C')
		return (data->game.coin);
	else
		return (data->game.floor);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->pars.map_str[i])
	{
		j = 0;
		while (data->pars.map_str[i][j])
		{
			c = data->pars.map_str[i][j];
			data->game.img = choose_img(data, c);
			mlx_put_image_to_window(data->game.mlx, data->game.win,
				data->game.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
