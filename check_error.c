/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:35:15 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/21 03:00:05 by nmellal          ###   ########.fr       */
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
		print_err("Invalid amount of Players");
	else if (data->exits != 1)
		print_err("Invalid amount of exits");
	else if (data->coins < 1)
		print_err("Invalid amount of Coins");
	check_edges(data);

}
void	check_edges(t_data *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		flag;

	tmp = data->pars.map_str;
	i = 0;
	flag = 0;
	while (tmp[i])
	{
		j = 0;
		if (!flag || i == count_strs(tmp) - 1)
		{
			while (tmp[i][j])
			{
				if (tmp[i][j] != '1')
				{
					print_err("Invalid map");
					flag = 1;
				}
				j++;
			}
		}
		else
		{
			if (tmp[i][0] != '1' || tmp[i][ft_strlen(tmp[i]) - 1] != '1')
				print_err("Invalid map");
		}
		{
			while (tmp[i][j])
			{
				if (tmp[i][j] != '1')
				{
					print_err("Invalid map");
					flag = 1;
				}
				j++;
			}
		}
	}
}

void	print_err(char *err_type)
{
	ft_putendl_fd(err_type, 2);
	exit(1);
}
