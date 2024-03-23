/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:35:53 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/23 04:12:17 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(t_data *data)
{
	int	i;
	int	j;

	data->pars.width = ft_strlen(data->pars.map_str[0]);
	data->pars.height = count_strs(data->pars.map_str);
	i = 0;
	while (data->pars.map_str[i])
	{
		j = 0;
		while (data->pars.map_str[i][j])
		{
			if (data->pars.map_str[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
void	flood_fill_coin(t_data *data, char **map, char **map_copy, int x, int y, int *collected_coins)
{
	if (x < 0 || y < 0 || x >= data->pars.width || y >= data->pars.height || map[y][x] == '1' || map[y][x] == 'E' || map_copy[y][x] == 'X')
		return ;
	map_copy[y][x] = 'X';
	if (map[y][x] == 'C')
		(*collected_coins)++;
	flood_fill_coin(data, map, map_copy, x + 1, y, collected_coins);
	flood_fill_coin(data, map, map_copy, x - 1, y, collected_coins);
	flood_fill_coin(data, map, map_copy, x, y + 1, collected_coins);
	flood_fill_coin(data, map, map_copy, x, y - 1, collected_coins);
}
int	flood_fill_exit(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->pars.width || y >= data->pars.height || data->pars.map_str[y][x] == '1' || data->pars.map_copy2[y][x] == 'X')
		return (0);
	if (data->pars.map_str[y][x] == 'E')
		return (1);
	data->pars.map_copy2[y][x] = 'X';
	if (flood_fill_exit(data, x + 1, y) || flood_fill_exit(data, x - 1, y) || flood_fill_exit(data, x, y + 1) || flood_fill_exit(data, x, y - 1))
		return (1);
	return (0);
}
void	check_path_for_player(t_data * data)
{
	int path_to_exit;

	find_player_pos(data);
	flood_fill_coin(data, data->pars.map_str, data->pars.map_copy ,data->player.x, data->player.y, &data->collected_coins);
	path_to_exit = flood_fill_exit(data, data->player.x, data->player.y);

	if (data->collected_coins != data->coins && path_to_exit == 0)
		print_err("You don't have the path to all the coins or to the exit", data);
	else if (data->collected_coins != data->coins)
		print_err("You don't have the path to all the coins", data);
	else if (path_to_exit == 0)
		print_err("No path to exit", data);
}
