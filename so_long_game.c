/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:08:52 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/25 19:53:46 by nmellal          ###   ########.fr       */
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
		if (data->player.y > 0 && data->pars.map_str[data->player.y - 1][data->player.x] != '1')
		{
			data->movements++;
			data->player.y -= 1;
./		}
	}
	else if (key == KEY_A)
	{
		data->player.texture = data->player.left;
		if (data->player.x > 0 && data->pars.map_str[data->player.y][data->player.x - 1] != '1')
		{
			data->movements++;
			data->player.x -= 1;
			ft_printf("Moves : %d\n", data->movements);
		}
	}
	else
		key_hook2(key, data);
	return (0);
}
void	key_hook2(int key, t_data*data)
{
	if (key == KEY_S)
	{
		data->player.texture = data->player.down;
		if (data->player.y < data->pars.height - 1 && data->pars.map_str[data->player.y + 1][data->player.x] != '1')
		{
			data->movements++;
			data->player.y++;
			ft_printf("Moves : %d\n", data->movements);
		}
	}
	else if (key == KEY_D)
	{
		data->player.texture = data->player.right;
		if(data->player.x < data->pars.width - 1 && data->pars.map_str[data->player.y][data->player.x + 1] != '1')
		{
			data->movements++;
			data->player.x ++;
			ft_printf("Moves : %d\n", data->movements);
		}
	}
}

void	check_player_postion(t_data*data)
{

	if (data->pars.map_str[data->player.y][data->player.x] == 'C')
	{
		data->pars.map_str[data->player.y][data->player.x] = '0';
		data->collected_coins++;
	}
	if (data->pars.map_str[data->player.y][data->player.x] == 'E' && data->collected_coins >= data->coins)
	{
		printf("coins %d\n", data->collected_coins);
		mlx_destroy_window(data->game.mlx, data->game.win);
		ft_putendl_fd("You won", 1);
		exit(0);
	}
}

int draw_frame(t_data*data)
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
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->player.texture[data->player.current_frame], data->player.x * 32, data->player.y * 32);
	return (0);
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
	define_textures2(data);
	data->player.texture = data->player.right;
	data->player.current_frame = 0;
	data->frames_elapsed = 0;
}

void	define_textures2(t_data *data)
{
	int height;
	int width;

	data->game.wall = mlx_xpm_file_to_image(data->game.mlx, "./imgs/wall.xpm", &height, &width);
	data->game.exit = mlx_xpm_file_to_image(data->game.mlx, "./imgs/exit.xpm", &height, &width);
	data->game.coin = mlx_xpm_file_to_image(data->game.mlx, "./imgs/Coin2.xpm", &height, &width);
	data->game.floor = mlx_xpm_file_to_image(data->game.mlx, "./imgs/black.xpm", &height, &width);
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
	int i;
	int j;
	char c;

	i = 0;
	while (data->pars.map_str[i])
	{
		j = 0;
		while (data->pars.map_str[i][j])
		{
			c = data->pars.map_str[i][j];
			data->game.img = choose_img(data, c);
			mlx_put_image_to_window(data->game.mlx, data->game.win, data->game.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
int	close_game(t_data *data)
{
	free(data->pars.filecontent);
	mlx_destroy_window(data->game.mlx, data->game.win);
	exit(0);
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
	mlx_hook(data->game.win, ON_DESTROY, 0, close_game, data);
	mlx_loop_hook(data->game.mlx, draw_frame, data);
	mlx_loop(data->game.mlx);
}
