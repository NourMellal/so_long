/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:23:40 by nmellal           #+#    #+#             */
/*   Updated: 2024/04/13 12:48:57 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_line(t_data *data)
{
	char	*s;
	char	*tmp;
	int		line_check;

	s = get_next_line(data->fd);
	if (s == NULL)
		print_err("Error\nInvalid map", data, 1);
	line_check = count_line(s);
	while (s)
	{
		tmp = ft_strjoin(data->pars.filecontent, s);
		if (!tmp)
		{
			free(s);
			print_err("Error\nMalloc failed", data, 1);
		}
		free(data->pars.filecontent);
		data->pars.filecontent = tmp;
		free(s);
		s = get_next_line(data->fd);
		if (s)
			check_line(data, s, line_check);
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
			print_err("Error\nInvalid map", data, 1);
		else
			collect_data(data, data->pars.filecontent[i]);
		i++;
	}
	data->pars.map_str = ft_split(data->pars.filecontent, '\n');
	data->pars.map_copy = ft_split(data->pars.filecontent, '\n');
	data->pars.map_copy2 = ft_split(data->pars.filecontent, '\n');
	check_data(data);
	free_2d_maps(data->pars.map_copy);
	free_2d_maps(data->pars.map_copy2);
	free(data->pars.filecontent);
}
