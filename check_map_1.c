/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaratas <akaratas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:25:31 by akaratas          #+#    #+#             */
/*   Updated: 2024/05/04 17:20:21 by akaratas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_file_check(char *file_path, t_game *game_p)
{
	int	ber_index;

	ber_index = ft_strlen(file_path) - 4;
	if (ber_index < 0)
		error("Your map's extension should be '.ber'", game_p);
	if (ft_strncmp(&(file_path[ber_index]), ".ber", 5) != 0)
		error("Your map's extension should be '.ber'", game_p);
}

void	map_wall_check(t_game *game_p)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < game_p->map_height)
	{
		line = (game_p->map)[i];
		if ((i == 0) || (i == (game_p->map_height - 1)))
		{
			j = 0;
			while (j < game_p->map_width)
			{
				if (line[j] != WALL)
					error("The map must be surrounded by walls.", game_p);
				j++;
			}
		}
		else
		{
			if (line[0] != WALL || line[game_p->map_width - 1] != WALL)
				error("The map must be closed/surrounded by walls.", game_p);
		}
		i++;
	}
}

void	map_character_counter(t_game *game_p, char character, int x, int y)
{
	if (character == ITEM)
		(game_p->counter).item++;
	else if (character == EXIT)
	{
		(game_p->counter).exit++;
		(game_p->exit_coordinate).x = x;
		(game_p->exit_coordinate).y = y;
	}
	else if (character == PLAYER)
	{
		(game_p->counter).player++;
		(game_p->player_coordinate).x = x;
		(game_p->player_coordinate).y = y;
	}
}

void	map_character_check(t_game *game_p)
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
			if (line[j] == WALL || line[j] == FLOOR || line[j] == ITEM
				|| line[j] == EXIT || line[j] == PLAYER)
				map_character_counter(game_p, line[j], j, i);
			else
				error("The map has only 5 characters(0-1-C-E-P)", game_p);
			j++;
		}
		i++;
	}
	if ((game_p->counter).item < 1 || (game_p->counter).exit != 1
		|| (game_p->counter).player != 1)
		error("The map must contain 1 E, at least 1 C, and 1 P.", game_p);
}

void	map_format_check(t_game *game_p)
{
	int		i;
	size_t	first_line_len;

	if ((game_p->map)[0] == NULL)
		error("There is nothing in the map file.", game_p);
	i = 0;
	first_line_len = ft_strlen((game_p->map)[0]);
	while (i < game_p->map_height)
	{
		if (ft_strlen((game_p->map)[i]) == 0)
			error("Map file line is empty.", game_p);
		if (ft_strlen((game_p->map)[i]) != first_line_len)
			error("The map must be rectangular.", game_p);
		i++;
	}
	game_p->map_width = first_line_len;
	map_wall_check(game_p);
	map_character_check(game_p);
	map_valid_path_check(game_p);
}
