/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:39:00 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/21 02:40:59 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
void	collect_data(t_data	*data, char byte)
{
		if (byte == 'P')
			data->players += 1;
		else if (byte == 'C')
			data->coins += 1;
		else if (byte == 'E')
			data->exits += 1;
}

int	check_line(t_data *data, char *s)
{
	int	i;

	if (!s)
		return (-1);
	data->pars.line_count += 1;
	i = 0;
	while (s[i] && i[s] != '\n')
		i++;
	return (i);
}
