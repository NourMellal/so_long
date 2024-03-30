/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:23:40 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/30 01:01:32 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_line(t_data *data)
{
	char	*s;
	int		line_check;
	int		line_check2;

	s = get_next_line(data->fd);
	if (s == NULL)
		print_err("Invalid map", data, 1);
	line_check = check_line(data, s);
	while (s)
	{
		data->pars.filecontent = ft_strjoin(data->pars.filecontent, s);
		free(s);
		s = get_next_line(data->fd);
		line_check2 = check_line(data, s);
		if (line_check != line_check2 && line_check2 != -1)
			print_err("Invalid map", data, 1);
	}
	s = NULL;
}

void	start_parsing(char *path, t_data *data)
{
	data->fd = open(path, O_RDONLY);
	if (data->fd < 0)
		print_error_file();
	get_line(data);
	check_if_valid_map(data);
}

void	check_if_valid_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->pars.filecontent[i])
	{
		if (data->pars.filecontent[i] != '0' && data->pars.filecontent[i] != '1'
			&& data->pars.filecontent[i] != 'P'
			&& data->pars.filecontent[i] != 'C'
			&& data->pars.filecontent[i] != 'E'
			&& data->pars.filecontent[i] != '\n')
			print_err("Invalid map", data, 1);
		else
			collect_data(data, data->pars.filecontent[i]);
		i++;
	}
	data->pars.map_str = ft_split(data->pars.filecontent, '\n');
	data->pars.map_copy = ft_split(data->pars.filecontent, '\n');
	data->pars.map_copy2 = ft_split(data->pars.filecontent, '\n');
	check_data(data);
	free_2d_maps(data->pars.map_str);
	free_2d_maps(data->pars.map_copy);
	free_2d_maps(data->pars.map_copy2);
	free(data->pars.filecontent);
}
