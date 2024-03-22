/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:35:53 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/22 17:33:01 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(t_data *data)
{
	int	i;
	int	j;

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
