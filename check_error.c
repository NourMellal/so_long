/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:35:15 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/22 03:31:05 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_err(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Too few arguments", 2);
		exit(1);
	}
	if (!check_path(av[1]))
	{
		ft_putendl_fd("Wrong file name!", 2);
		exit(1);
	}
}
int	check_path(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	str += len - 4;
	if (strcmp(".ber", str) == 0)
		return (1);
	else
		return (0);
}

void	check_data(t_data *data)
{
	if (data->players != 1)
		print_err("Invalid amount of Players", data);
	else if (data->exits != 1)
		print_err("Invalid amount of exits", data);
	else if (data->coins < 1)
		print_err("Invalid amount of Coins", data);
	check_edges(data);
}

void	check_edges(t_data *data)
{
	char	**tmp;
	int		i;

	tmp = data->pars.map_str;
	i = 0;
	while (tmp[i])
	{
		if (i == count_strs(tmp) - 1 || i == 0)
			last_and_first_line(tmp[i], data);
		else
			inner_lines(tmp[i], data);
		i++;
	}
}

void	print_err(char *err_type, t_data *data)
{
	int i;

	i = 0;
	if (data->pars.filecontent)
		free(data->pars.filecontent);
	if (data->pars.map_str)
	{
		while (data->pars.map_str[i])
		{
			free(data->pars.map_str[i]);
			i++;
		}
		free(data->pars.map_str);
	}
	ft_putendl_fd(err_type, 2);
	exit(1);
}
