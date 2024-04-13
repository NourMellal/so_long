/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:47:11 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/13 12:49:56 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_file(void)
{
	ft_putendl_fd("Error\nFile can't open", 2);
	exit(1);
}

void	define_data(t_data *data)
{
	data->players = 0;
	data->exits = 0;
	data->coins = 0;
	data->collected_coins = 0;
	data->pars.line_count = 0;
	data->frames_elapsed = 0;
	data->game.flag = 1;
	data->movements = 0;
	data->pars.filecontent = NULL;
	data->game.mlx = NULL;
	data->pars.map_str = NULL;
	data->pars.map_copy = NULL;
	data->pars.map_copy2 = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	check_for_err(ac, av);
	define_data(&data);
	start_parsing(av[1], &data);
	data.collected_coins = 0;
	start_game(&data);
	free_2d_maps(data.pars.map_str);
	return (0);
}
