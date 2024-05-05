/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:23:22 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 17:23:22 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_game *game_p, int y, int x)
{
	static int	counter;

	(game_p->player_coordinate).y = y;
	(game_p->player_coordinate).x = x;
	ft_printf("the current number of movements: %d\n", ++counter);
}

void	check_path(t_game *game_p, char character, int y, int x)
{
	if (character == FLOOR)
		update_player_position(game_p, y, x);
	else if (character == ITEM)
	{
		update_player_position(game_p, y, x);
		((game_p->counter).item)--;
	}
	else if (character == EXIT)
	{
		update_player_position(game_p, y, x);
		if ((game_p->counter).item == 0)
		{
			mlx_destroy_window(game_p->mlx_ptr, game_p->win_ptr);
			error("---------------- THE END ----------------", game_p);
		}
	}
}

int	key_handler(int keycode, t_game *game_p)
{
	int	y;
	int	x;

	y = (game_p->player_coordinate).y;
	x = (game_p->player_coordinate).x;
	if (keycode == KEY_ESC)
		close_handler(game_p);
	else if ((keycode == KEY_RIGHT) || (keycode == KEY_D))
		check_path(game_p, (game_p->map)[y][x + 1], y, (x + 1));
	else if ((keycode == KEY_LEFT) || (keycode == KEY_A))
		check_path(game_p, (game_p->map)[y][x - 1], y, (x - 1));
	else if ((keycode == KEY_UP) || (keycode == KEY_W))
		check_path(game_p, (game_p->map)[y - 1][x], (y - 1), x);
	else if ((keycode == KEY_DOWN) || (keycode == KEY_S))
		check_path(game_p, (game_p->map)[y + 1][x], (y + 1), x);
	else
		return (0);
	(game_p->map)[y][x] = FLOOR;
	(game_p->map)
	[(game_p->exit_coordinate).y][(game_p->exit_coordinate).x] = EXIT;
	(game_p->map)
	[(game_p->player_coordinate).y][(game_p->player_coordinate).x] = PLAYER;
	put_image_to_window(game_p);
	return (0);
}
