/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:45:33 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/31 10:43:01 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	start_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if (data->game.mlx == NULL)
		print_err("mlx_init failed", data, 1);
	data->game.win = mlx_new_window(data->game.mlx, data->pars.width * 32,
			data->pars.height * 32, "so_long");
	if (data->game.win == NULL)
		print_err("mlx_new_window failed", data, 1);
	define_textures(data);
	mlx_hook(data->game.win, 2, 1L << 0, key_hook, data);
	// mlx_hook(data->game.win, ON_DESTROY, 0, close_game, data);
	mlx_loop_hook(data->game.mlx, draw_frame, data);
	mlx_loop(data->game.mlx);
}
