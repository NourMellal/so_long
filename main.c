/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:47:11 by nmellal           #+#    #+#             */
/*   Updated: 2024/03/20 23:01:48 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_file(void)
{
	ft_putendl_fd("File can't open", 2);
	exit(1);
}


int	main(int ac, char **av)
{
	t_data	data;
	check_for_err(ac, av);
	start_parsing(av[1], &data);

	close(data.fd);
	return (0);
}

