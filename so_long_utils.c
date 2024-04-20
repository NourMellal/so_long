/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:39:00 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/20 18:23:27 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	collect_data(t_data *data, char byte)
{
	if (byte == 'P')
		data->players += 1;
	else if (byte == 'C')
		data->coins += 1;
	else if (byte == 'E')
		data->exits += 1;
}

void	check_line(t_data *data, char *s, long line)
{
	int	i;

	if (!s)
	{
		free(data->pars.filecontent);
		print_err("Error\nInvalid map", data, 1);
	}
	data->pars.line_count += 1;
	if (data->pars.line_count * 30 > MAX_HEIGHT || line * 30 > MAX_WIDTH)
	{
		free(s);
		free(data->pars.filecontent);
		system("leaks so_long");
		print_err("Error\nThe map is big try to adjust it", data, 1);
	}
	i = 0;
	while (s[i] && i[s] != '\n')
		i++;
	if (line != i)
	{
		free(s);
		free(data->pars.filecontent);
		print_err("Error\nInvalid map", data, 1);
	}
}

void	last_and_first_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			print_err("Error\nInvalid map", data, 1);
		i++;
	}
}

void	inner_lines(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		print_err("Error\nInvalid map", data, 1);
	i++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E')
			print_err("Error\nInvalid map", data, 1);
		i++;
	}
	if (str[i - 1] != '1')
		print_err("Error\nInvalid map", data, 1);
}
