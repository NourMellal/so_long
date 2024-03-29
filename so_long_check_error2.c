/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_error2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:58:05 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/29 02:01:37 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free3(t_data *data)
{
	if (data->game.mlx)
	{
		free(data->game.mlx);
		mlx_destroy_window(data->game.mlx, data->game.win);
	}
}

void	free2(t_data *data)
{
	int	i;

	i = 0;
	if (data->pars.map_copy)
	{
		while (data->pars.map_copy[i])
		{
			free(data->pars.map_copy[i]);
			i++;
		}
		free(data->pars.map_copy);
	}
	if (data->pars.map_copy2)
	{
		i = 0;
		while (data->pars.map_copy2[i])
		{
			free(data->pars.map_copy2[i]);
			i++;
		}
		free(data->pars.map_copy2);
	}
	free3(data);
}
