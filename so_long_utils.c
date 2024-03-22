/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:39:00 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/22 03:29:44 by nmellal          ###   ########.fr       */
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
void	last_and_first_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			print_err("Invalid map", data);
		i++;
	}
}
void	inner_lines(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		print_err("Invalid map", data);
	i++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P' && str[i] != 'C' && str[i] != 'E')
			print_err("Invalid map", data);
		i++;
	}
	if (str[i - 1] != '1')
		print_err("Invalid map", data);
}
