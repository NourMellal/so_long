/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:35:15 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/30 01:06:54 by nmellal          ###   ########.fr       */
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
		print_err("Invalid amount of Players", data, 1);
	else if (data->exits != 1)
		print_err("Invalid amount of exits", data, 1);
	else if (data->coins < 1)
		print_err("Invalid amount of Coins", data, 1);
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
	check_path_for_player(data);
}

void	print_err(char *err_type, t_data *data, int print_err)
{
	int	i;

	i = 0;
	if (data->game.mlx)
	{
		mlx_destroy_window(data->game.mlx, data->game.win);
		free(data->game.mlx);
	}
	if (print_err)
	{
		ft_putendl_fd(err_type, 2);
		close(data->fd);
		exit(1);
	}
}
