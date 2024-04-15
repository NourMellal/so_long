/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:44:57 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/15 14:40:03 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *data)
{
	if (key == KEY_ESC)
	{
		free_2d_maps(data->pars.map_str);
		print_err("", data, 0);
		exit(0);
	}
	else if (key == KEY_W)
		w_key(data);
	else if (key == KEY_A)
		a_key(data);
	else if (key == KEY_S)
		s_key(data);
	else if (key == KEY_D)
		d_key(data);
	return (0);
}

void	define_textures2(t_data *data)
{
	int	height;
	int	width;

	data->game.wall = mlx_xpm_file_to_image(data->game.mlx, "textures/wall.xpm",
			&height, &width);
	data->game.exit = mlx_xpm_file_to_image(data->game.mlx, "textures/exit.xpm",
			&height, &width);
	data->game.coin = mlx_xpm_file_to_image(data->game.mlx,
			"textures/Coin2.xpm", &height, &width);
	data->game.floor = mlx_xpm_file_to_image(data->game.mlx,
			"textures/black.xpm", &height, &width);
	data->game.moves = mlx_xpm_file_to_image(data->game.mlx,
			"textures/move.xpm", &height, &width);
}

void	define_textures3(t_data *data)
{
	int	height;
	int	width;

	data->player.left[0] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_left1.xpm", &height, &width);
	data->player.left[1] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_left2.xpm", &height, &width);
	data->player.left[2] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_left3.xpm", &height, &width);
	data->player.left[3] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_left4.xpm", &height, &width);
	data->player.right[0] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_right1.xpm", &height, &width);
	data->player.right[1] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_right2.xpm", &height, &width);
	data->player.right[2] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_right3.xpm", &height, &width);
	data->player.right[3] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_right4.xpm", &height, &width);
	define_textures2(data);
	data->player.texture = data->player.right;
	data->player.current_frame = 0;
	data->frames_elapsed = 0;
}

void	define_textures(t_data *data)
{
	int	height;
	int	width;

	data->player.up[0] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_up1.xpm", &height, &width);
	data->player.up[1] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_up2.xpm", &height, &width);
	data->player.up[2] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_up3.xpm", &height, &width);
	data->player.up[3] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_up4.xpm", &height, &width);
	data->player.down[0] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_down1.xpm", &height, &width);
	data->player.down[1] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_down2.xpm", &height, &width);
	data->player.down[2] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_down3.xpm", &height, &width);
	data->player.down[3] = mlx_xpm_file_to_image(data->game.mlx,
			"textures/pac_down4.xpm", &height, &width);
	define_textures3(data);
}
