/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:35:27 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 18:55:23 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_to_window_2(t_game *game_p, char character, int i, int j)
{
	mlx_put_image_to_window(game_p->mlx_ptr, game_p->win_ptr,
		(game_p->img_ptr).floor, j, i);
	if (character == WALL)
		mlx_put_image_to_window(game_p->mlx_ptr, game_p->win_ptr,
			(game_p->img_ptr).wall, j, i);
	else if (character == PLAYER)
		mlx_put_image_to_window(game_p->mlx_ptr, game_p->win_ptr,
			(game_p->img_ptr).player, j, i);
	else if (character == ITEM)
		mlx_put_image_to_window(game_p->mlx_ptr, game_p->win_ptr,
			(game_p->img_ptr).item, j, i);
	else if (character == EXIT)
		mlx_put_image_to_window(game_p->mlx_ptr, game_p->win_ptr,
			(game_p->img_ptr).exit, j, i);
}

void	put_image_to_window(t_game *game_p)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < game_p->map_height)
	{
		line = (game_p->map)[i];
		j = 0;
		while (j < game_p->map_width)
		{
			put_image_to_window_2(game_p, line[j], (i * 50), (j * 50));
			j++;
		}
		i++;
	}
}

void	init_image_to_mlx(t_game *game_p)
{
	int	width;
	int	height;

	(game_p->img_ptr).floor = mlx_xpm_file_to_image(game_p->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	if ((game_p->img_ptr).floor == NULL)
		error("floor image cannot be initialized", game_p);
	(game_p->img_ptr).wall = mlx_xpm_file_to_image(game_p->mlx_ptr,
			"textures/wall.xpm", &width, &height);
	if ((game_p->img_ptr).wall == NULL)
		error("wall image cannot be initialized", game_p);
	(game_p->img_ptr).player = mlx_xpm_file_to_image(game_p->mlx_ptr,
			"textures/player.xpm", &width, &height);
	if ((game_p->img_ptr).player == NULL)
		error("player image cannot be initialized", game_p);
	(game_p->img_ptr).item = mlx_xpm_file_to_image(game_p->mlx_ptr,
			"textures/item.xpm", &width, &height);
	if ((game_p->img_ptr).item == NULL)
		error("item image cannot be initialized", game_p);
	(game_p->img_ptr).exit = mlx_xpm_file_to_image(game_p->mlx_ptr,
			"textures/exit.xpm", &width, &height);
	if ((game_p->img_ptr).player == NULL)
		error("exit image cannot be initialized", game_p);
}

int	close_handler(t_game *game_p)
{
	mlx_destroy_window(game_p->mlx_ptr, game_p->win_ptr);
	error("Destroy Window", game_p);
	return (0);
}

void	create_mlx_window(t_game *game_p)
{
	if ((game_p->map_height > 26) || game_p->map_width > 52)
		error("The window size is so big!", game_p);
	game_p->mlx_ptr = mlx_init();
	if (game_p->mlx_ptr == NULL)
		error("mlx_ptr cannot be initialized", game_p);
	game_p->win_ptr = mlx_new_window(game_p->mlx_ptr, (game_p->map_width) * 50,
			(game_p->map_height) * 50, "so_long");
	if (game_p->win_ptr == NULL)
		error("win_ptr cannot be initialized", game_p);
	init_image_to_mlx(game_p);
	put_image_to_window(game_p);
	mlx_hook(game_p->win_ptr, KEY_PRESS_EVENT, 0, key_handler, game_p);
	mlx_hook(game_p->win_ptr, EXIT_BUTTON_EVENT, 0, close_handler, game_p);
	mlx_loop(game_p->mlx_ptr);
}
