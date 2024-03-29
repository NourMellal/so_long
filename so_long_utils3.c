/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:50:54 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/29 01:46:35 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(t_data *data)
{
	data->player.texture = data->player.up;
	if (data->player.y > 0
		&& data->pars.map_str[data->player.y - 1][data->player.x] != '1')
	{
		data->movements++;
		data->player.y--;
		ft_printf("Moves : %d\n", data->movements);
	}
}

void	a_key(t_data *data)
{
	data->player.texture = data->player.left;
	if (data->player.x > 0
		&& data->pars.map_str[data->player.y][data->player.x - 1] != '1')
	{
		data->movements++;
		data->player.x--;
		ft_printf("Moves : %d\n", data->movements);
	}
}

void	s_key(t_data *data)
{
	data->player.texture = data->player.down;
	if (data->player.y < data->pars.height - 1
		&& data->pars.map_str[data->player.y + 1][data->player.x] != '1')
	{
		data->movements++;
		data->player.y++;
		ft_printf("Moves : %d\n", data->movements);
	}
}

void	d_key(t_data *data)
{
	data->player.texture = data->player.right;
	if (data->player.x < data->pars.width - 1
		&& data->pars.map_str[data->player.y][data->player.x + 1] != '1')
	{
		data->movements++;
		data->player.x++;
		ft_printf("Moves : %d\n", data->movements);
	}
}

