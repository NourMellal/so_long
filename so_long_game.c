/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:08:52 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/25 00:21:34 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int key, t_data*data)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->game.mlx, data->game.win);
		exit(0);
	}
	else if (key == KEY_W)
	{
		data->player.texture = data->player.up;
		data->player.y -= 32;
	}
	else if (key == KEY_A)
	{
		data->player.texture = data->player.left;
		data->player.x -= 32;
	}
	else if (key == KEY_S)
	{
		data->player.texture = data->player.down;
		data->player.y += 32;
	}
	else if (key == KEY_D)
	{
		data->player.texture = data->player.right;
		data->player.x += 32;
	}
}

int draw_frame(t_data*data)
{
	mlx_clear_window(data->game.mlx, data->game.win);
	data->frames_elapsed++;
	if (data->frames_elapsed == 10)
	{
		data->player.current_frame = (data->player.current_frame + 1) % 4;
		data->frames_elapsed = 0;
	}
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->player.texture[data->player.current_frame], data->player.x, data->player.y);
}
void	define_textures(t_data *data)
{
	int height;
	int width;
	data->player.up[0] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_up1.xpm", &height, &width);
	data->player.up[1] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_up2.xpm", &height, &width);
	data->player.up[2] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_up3.xpm", &height, &width);
	data->player.up[3] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_up4.xpm", &height, &width);
	data->player.down[0] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_down1.xpm", &height, &width);
	data->player.down[1] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_down2.xpm", &height, &width);
	data->player.down[2] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_down3.xpm", &height, &width);
	data->player.down[3] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_down4.xpm", &height, &width);
	data->player.left[0] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_left1.xpm", &height, &width);
	data->player.left[1] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_left2.xpm", &height, &width);
	data->player.left[2] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_left3.xpm", &height, &width);
	data->player.left[3] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_left4.xpm", &height, &width);
	data->player.right[0] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_right1.xpm", &height, &width);
	data->player.right[1] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_right2.xpm", &height, &width);
	data->player.right[2] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_right3.xpm", &height, &width);
	data->player.right[3] = mlx_xpm_file_to_image(data->game.mlx, "./imgs/pac_right4.xpm", &height, &width);
	data->player.texture = data->player.right;
	data->player.current_frame = 0;
	data->frames_elapsed = 0;
}

void	start_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if (data->game.mlx == NULL)
		print_err("mlx_init failed", data);
	data->game.win = mlx_new_window(data->game.mlx, data->pars.width * 32,
			data->pars.height * 32, "so_long");
	if (data->game.win == NULL)
		print_err("mlx_new_window failed", data);
	define_textures(data);
	mlx_hook(data->game.win, 2, 1L << 0, key_hook, data);
	mlx_loop_hook(data->game.mlx, draw_frame, data);
	mlx_loop(data->game.mlx);
}
