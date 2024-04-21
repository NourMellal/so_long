/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:50:54 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/15 13:58:37 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(t_data *data)
{
	data->player.texture = data->player.up;
	if (data->player.y > 0 && data->pars.map_str[data->player.y
			- 1][data->player.x] != '1' && data->pars.map_str[data->player.y
		- 1][data->player.x] != 'E')
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.y--;
	}
	else if (data->pars.map_str[data->player.y - 1][data->player.x] == 'E'
		&& data->collected_coins >= data->coins)
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.y--;
	}
}

void	a_key(t_data *data)
{
	data->player.texture = data->player.left;
	if (data->player.x > 0 && data->pars.map_str[data->player.y][data->player.x
		- 1] != '1' && data->pars.map_str[data->player.y][data->player.x
		- 1] != 'E')
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.x--;
	}
	else if (data->pars.map_str[data->player.y][data->player.x - 1] == 'E'
		&& data->collected_coins >= data->coins)
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.x--;
	}
}

void	s_key(t_data *data)
{
	data->player.texture = data->player.down;
	if (data->player.y < data->pars.height - 1
		&& data->pars.map_str[data->player.y + 1][data->player.x] != '1'
		&& data->pars.map_str[data->player.y + 1][data->player.x] != 'E')
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.y++;
	}
	else if (data->pars.map_str[data->player.y + 1][data->player.x] == 'E'
		&& data->collected_coins >= data->coins)
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.y++;
	}
}

void	d_key(t_data *data)
{
	data->player.texture = data->player.right;
	if (data->player.x < data->pars.width - 1
		&& data->pars.map_str[data->player.y][data->player.x + 1] != '1'
		&& data->pars.map_str[data->player.y][data->player.x + 1] != 'E')
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.x++;
	}
	else if (data->pars.map_str[data->player.y][data->player.x + 1] == 'E'
		&& data->collected_coins >= data->coins)
	{
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->game.floor, data->player.x * 32, data->player.y * 32);
		data->movements++;
		data->player.x++;
	}
}

int	count_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
