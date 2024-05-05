/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:08:42 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/05 23:40:59 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_game	game;

	if (ac != 2)
		error("Check to parameters!", &game);
	create_map(&game, av[1]);
	map_format_check(&game);
	create_mlx_window(&game);
	free_map(game.map);
	return (0);
}

/*memory leak check function*/
__attribute__((destructor)) static void	test(void)
{
	ft_printf("\n");
	system("leaks so_long");
}
